#include "Error.h"
#include "Lexer.h"
#include "Parser.h"
#include "Table.h"

namespace Parser {
    double prim(bool);
    double term(bool);

    using Error::error;
    using Table::table;
    using namespace Lexer;

    double expr(bool get) {

        double left = term(get);
        for (;;) {
            switch (ts.current().kind) {
            case Kind::plus:
                left += term(true);
                break;
            case Lexer::Kind::minus:
                left -= term(true);
                break;
            default:
                return left;
            }
        }
    }

    double prim(bool get) {
        if (get)
            ts.get();

        switch (ts.current().kind) {
        case Kind::number: {
            double v = ts.current().symbol.number_value;
            ts.get();
            return v;
        }
        case Kind::name: {
            double& v = table[ts.current().symbol.string_value];
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

    double term(bool get) {
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
} // namespace Parser
