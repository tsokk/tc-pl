#ifndef CALC_DRIVER_H
#define CALC_DRIVER_H

#include "Lexer.h"
#include "Parser.h"

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
            std::cout << expr(false) << '\n';
        }
    }
} // namespace Driver

#endif // !CALC_DRIVER_H
