#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

namespace Parser {
double expr(bool);
}

namespace Error {
  int lineno = 1;
  int no_of_errors;

  double error(const string &s) {
    no_of_errors++;
    cerr << "error on line " << lineno << ": " << s << '\n';
    return 1;
  }
}

namespace Lexer {
enum class Kind : char {
  name,
  number,
  end,
  plus = '+',
  minus = '-',
  mul = '*',
  div = '/',
  print = ';',
  assign = '=',
  lp = '(',
  rp = ')'
};

struct Symbol {
  string string_value;
  double number_value;
};

struct Token {
  Kind kind;
  Symbol symbol;
};

// input
class Token_stream {
public:
  Token_stream(istream &s) : ip{&s}, owns{false} {}
  Token_stream(istream *p) : ip{p}, owns{true} {}

  ~Token_stream() { close(); }

  Token get();
  const Token &current() { return ct; };

  void set_input(istream &s) {
    close();
    ip = &s;
    owns = false;
  }
  void set_input(istream *p) {
    close();
    ip = p;
    owns = true;
  }

private:
  void close() {
    if (owns)
      delete ip;
  }

  istream *ip;
  bool owns;
  Token ct{Kind::end};
};

Token Token_stream::get() {
  char ch;

  do {
    if (!ip->get(ch))
      return ct = {Kind::end};
  } while (ch != '\n' && isspace(ch));

  switch (ch) {
  case ';':
  case '\n':
    Error::lineno++;
    return ct = {Kind::print};
  case '*':
  case '/':
  case '+':
  case '-':
  case '(':
  case ')':
  case '=':
    return ct = {static_cast<Kind>(ch)};
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  case '.':
    ip->putback(ch);
    *ip >> ct.symbol.number_value;
    ct.kind = Kind::number;
    return ct;
  default:
    if (isalpha(ch)) {
      ct.symbol.string_value += ch;
      while (ip->get(ch)) {
        if (isalnum(ch)) {
          ct.symbol.string_value += ch;
        } else {
          ip->putback(ch);
          break;
        }
      }
      ct.kind = Kind::name;
      return ct;
    }
    Error::error("bad token");
    return ct = {Kind::print};
  }
}

Token_stream ts{cin};
} // namespace Lexer

namespace Table {
map<string, double> table;
}

namespace Parser_impl {
using namespace Parser;

double prim(bool);
double term(bool);

using namespace Lexer;
using Error::error;
using Table::table;
}

double Parser::expr(bool get) {
  using namespace Parser_impl;

  double left = term(get);
  for (;;) {
    switch (ts.current().kind) {
    case Kind::plus:
      left += term(true);
      break;
    case Kind::minus:
      left -= term(true);
      break;
    default:
      return left;
    }
  }
}

double Parser_impl::prim(bool get) {
  if (get)
    ts.get();

  switch (ts.current().kind) {
  case Kind::number: {
    double v = ts.current().symbol.number_value;
    ts.get();
    return v;
  }
  case Kind::name: {
    double &v = table[ts.current().symbol.string_value];
    if (ts.get().kind == Kind::assign)
      v = expr(true);
    return v;
  }
  case Kind::minus:
    return -prim(true);
  case Kind::lp: {
    auto e = expr(true);
    if (ts.current().kind != Kind::rp)
      return error("')' expected");
    ts.get();
    return e;
  }
  default:
    return error("primary expected");
  }
}

double Parser_impl::term(bool get) {
  double left = prim(get);

  for (;;) {
    switch (ts.current().kind) {
    case Kind::mul:
      left *= prim(true);
      break;
    case Kind::div:
      if (auto d = prim(true)) {
        left /= d;
        break;
      }
      return error("divide by 0");
    default:
      return left;
    }
  }
}

namespace Driver {
using namespace Lexer;
using namespace Parser;

void calculate() {
  for (;;) {
    ts.get();
    if (ts.current().kind == Kind::end)
      break;
    if (ts.current().kind == Kind::print)
      continue;
    cout << expr(false) << '\n';
  }
}
} // namespace Driver

int main(int argc, char *argv[]) {
  switch (argc) {
  case 1:
    break;
  case 2:
    Lexer::ts.set_input(new istringstream{argv[1]});
    break;
  default:
    Error::error("too many arguments");
    return 1;
  }
  Table::table["pi"] = 3.1415926535897932385;
  Table::table["e"] = 2.7182818284590452354;

  Driver::calculate();

  return Error::no_of_errors;
}
