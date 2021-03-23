#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>

namespace lin_alg {
using namespace boost::numeric::ublas;
template <typename T>
bool invert_matrix(const matrix<T> &input, matrix<T> &inverse) {
  matrix<T> A(input);
  permutation_matrix<std::size_t> pm(A.size1());

  int res = lu_factorize(A, pm);
  if (res != 0)
    return false;

  inverse.assign(identity_matrix<T>(A.size1()));
  lu_substitute(A, pm, inverse);

  return true;
}
} // namespace lin_alg

namespace helper {
using namespace boost::numeric::ublas;
matrix<double> populate() {
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
  return m;
}
} // namespace helper

int main() {
  using namespace boost::numeric::ublas;
  matrix<double> m = helper::populate();
  std::cout << m << '\n';

  matrix<double> n(3, 3);
  bool exists = lin_alg::invert_matrix(m, n);
  if (exists)
    std::cout << n << '\n';
}
