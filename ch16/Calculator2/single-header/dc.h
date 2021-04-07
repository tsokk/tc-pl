#include <map>
#include <string>
#include <iostream>
using namespace std;

namespace Parser {
    double expr(bool);
    double term(bool);
    double prim(bool);
}

namespace Lexer {
    enum class Kind : char {
        name, number, end,
	plus='+', minus='-', mul='*', div='/', print=';', assign='=',
	lp='(', rp=')'
    };

    struct Symbol {
        string string_value;
        double number_value;
    };

    struct Token {
        Kind kind;
        Symbol symbol;
    };

    class Token_stream {
    public:
        Token_stream(istream& s) : ip{&s}, owns{false}, ct{Kind::end} {}
        Token_stream(istream* p) : ip{p}, owns{true}, ct{Kind::end} {}

        ~Token_stream() {close();}

        Token get();
        Token& current();

        void set_input(istream& s) {close(); ip = &s; owns = false;}
        void set_input(istream* p) {close(); ip = p; owns = true;}

    private:
        void close() {if (owns) delete ip;}

        istream* ip;
        bool owns;
        Token ct{Kind::end};
    };

    extern Token_stream ts;
}

namespace Table {
    extern map<string,double> table;
}

namespace Error {
    extern int no_of_errors;
    extern int lineno;
    double error(const string& s);
}

namespace Driver {
    void calculate();
}
