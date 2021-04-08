#include "parser.h"
#include "error.h"
#include "lexer.h"

using Error::error;
using namespace Lexer;

namespace Parser { // interface for implementers
    double prim(bool get);
    double term(bool get);
    double expr(bool get);
}
