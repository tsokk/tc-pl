#include <exception>
#include <iostream>

using namespace std;

template <typename T> class Checked_ptr {
  T *p;
  int *i;
  int *space;

public:
  Checked_ptr(T *pp, const int sz) : p{pp}, i{pp}, space{pp + sz} {
    if (p == nullptr)
      throw runtime_error("Checked_ptr: null pointer");
  }
  void operator++() {
    if (i >= space)
      throw runtime_error(
          "Checked_ptr: attempt to refer to one-beyond-the-end");
    else
      ++i;
  }
  void operator--() {
    if (i <= p)
      throw runtime_error(
          "Checked_ptr: attempt to refer to one-before-the-beginning");
    else
      --i;
  }
};

int main() try {
  Checked_ptr<int> pa = {new int[3], 3};
  ++pa;
  Checked_ptr<int> qa = {nullptr, 0};
} catch (exception &e) {
  cerr << e.what() << '\n';
}
