#include "error.h"
#include "lexer.h"
#include <cctype>
#include <iostream>

Lexer::Token_stream Lexer::ts{std::cin};

Lexer::Token Lexer::Token_stream::get()
{
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
                }
                else {
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

Lexer::Token& Lexer::Token_stream::current() { return ct; }
