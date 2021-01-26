#include <iostream>

int main()
	// There seems to be no limit to the name that g++ can handle
	// perhaps only the memory is the limit
	// see also:
	// https://stackoverflow.com/questions/2682027/is-there-a-length-limit-on-g-variable-names
	// Regarding restrictions on characters that can be used in an identifier, see g++(1), and
	// especially the documentation on -Wnormalized=[none|id|nfc|nfkc] compiler option.
{
	std::cout << "#include <iostream>\n"
		<< "int main()\n{\n\t";
	std::cout << "extern int ";
	for (int i=0; i<100000; i++)
		std::cout << "asdf";
	std::cout << ";\n";
	std::cout << "}\n";
}