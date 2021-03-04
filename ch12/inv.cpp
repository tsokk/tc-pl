#include <invert_matrix.hpp>
#include <iostream>

int main() {
	using namespace boost::numeric::ublas;
  matrix<double> m(3, 3);
	m.insert_element(0, 0, 3);
	m.insert_element(0, 1, 0);
	m.insert_element(0, 2, 2);
	m.insert_element(1, 0, 2);
	m.insert_element(1, 1, 0);
	m.insert_element(1, 2, -2);
	m.insert_element(2, 0, 0);
	m.insert_element(2, 1, 1);
	m.insert_element(2, 2, 1);
  std::cout << m << '\n';
	matrix<double> n(3, 3);
	bool exists = InvertMatrix(m, n);
	if (exists)
		std::cout << n << '\n';
}
