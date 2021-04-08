#include "error.h"
#include <iostream>

int Error::no_of_errors;
int Error::lineno = 1;

double Error::error(const std::string& s) {
    Error::no_of_errors++;
    std::cerr << "error on line " << lineno << ": " << s << '\n';
    return 1;
}
