void f(char c) {}
void g(char& c) {}
void h(const char& c) {}

int main()
{
	f('a');
	// g('a');	cannot bind non-const lvalue reference of type ”char&” to an rvalue of type ”char”
	h('a');		// makes a temporary and binds it to c

	f(49);
	// g(49);	cannot bind non-const lvalue reference of type ”char&” to an rvalue of type ”char”
	h(49);	// makes a temporary and binds it to c

	// f(3300);	warning: overflow
	// g(3300);	cannot bind non-const lvalue reference of type ”char&” to an rvalue of type ”char”
	// h(3300);	warning: overflow

	char c =  'c';
	unsigned char uc = 'd';
	signed char sc = 'e';

	f(c);
	g(c);
	h(c);

	f(uc);
	// g(uc);	cannot bind non-const lvalue reference of type ”char&” to an rvalue of type ”char”
	h(uc);		// makes a temporary and binds it to uc

	f(sc);
	// g(sc);	cannot bind non-const lvalue reference of type ”char&” to an rvalue of type ”char”
	h(sc);		// makes as temporary and binds it to sc
}