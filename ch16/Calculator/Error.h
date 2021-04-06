#ifndef CALC_ERROR_H
#define CALC_ERROR_H

#include <string>
#include <iostream>

namespace Error {
    int lineno = 1;
    int no_of_errors;

    double error(const std::string& s) {
        no_of_errors++;
        std::cerr << "error on line " << lineno << ": " << s << '\n';
        return 1;
    }
}

#endif // !CALC_ERROR_H