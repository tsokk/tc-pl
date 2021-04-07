#include "dc.h"

int Error::no_of_errors;
int Error::lineno;

double Error::error(const string& s) {
    no_of_errors++;
    cerr << "error on line " << lineno << ": " << s << '\n';
    return 1;
}
