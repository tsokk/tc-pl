#ifndef CALC_LEXER_H
#define CALC_LEXER_H

#include <iostream>
#include <string>

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
        std::string string_value;
        double number_value;
    };

    struct Token {
        Kind kind;
        Symbol symbol;
    };

    class Token_stream {
    public:
        Token_stream(std::istream& s) : ip{ &s }, owns{ false } {}
        Token_stream(std::istream* p) : ip{ p }, owns{ true } {}

        ~Token_stream() { close(); }

        Token get();
        const Token& current() { return ct; };

        void set_input(std::istream& s) {
            close();
            ip = &s;
            owns = false;
        }
        void set_input(std::istream* p) {
            close();
            ip = p;
            owns = true;
        }

    private:
        void close() {
            if (owns)
                delete ip;
        }

        std::istream* ip;
        bool owns;
        Token ct{ Kind::end };
    };

    Token_stream ts{ std::cin };

} // namespace Lexer

#endif // !CALC_LEXER_H
