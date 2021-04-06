#include "Error.h"
#include "Lexer.h"
#include "Table.h"
#include "Driver.h"
#include <sstream>

int main(int argc, char* argv[]) {
    switch (argc) {
    case 1:
        break;
    case 2:
        Lexer::ts.set_input(new std::istringstream{ argv[1] });
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
