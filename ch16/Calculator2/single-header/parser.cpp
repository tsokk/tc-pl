#include "dc.h"
using namespace Lexer;
using namespace Table;

double Parser::prim(bool get)
{
    if (get) ts.get();

    switch(ts.current().kind) {
    case Kind::number:
    {
	double v = ts.current().symbol.number_value;
	ts.get();
	return v;
    }
    case Kind::name:
    {
	double &v = table[ts.current().symbol.string_value];
	if (ts.get().kind == Kind::assign)
	    v = Parser::expr(true);
	return v;
    }
    case Kind::minus:
	return -prim(true);
    case Kind::lp:
    {
	auto e = Parser::expr(true);
	if (ts.current().kind != Kind::rp)
	    return Error::error("')' expected");
	ts.get();
	return e;
    }
    default:
	return Error::error("primary expected");
    }
}

double Parser::term(bool get)
{
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
	    return Error::error("divide by 0");
	default:
	    return left;
	}
    }
}

double Parser::expr(bool get)
{
    double left = term(get);
    for (;;) {
	switch (ts.current().kind) {
	case Kind::plus:
	    left += term(true);
	    break;
	case Kind::minus:
	    left -= term(true);
	    break;
	default:
	    return left;
	}
    }
}
