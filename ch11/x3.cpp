#include <iostream>
#include <vector>

using namespace std;

class Shape {
  const double sz;
public:
  Shape(double s) :sz{s}{ }
  double size() { return sz; }
};

vector<double> apply(vector<Shape*>& v, double f(Shape*)) {
  vector<double> res;
  for (const auto& s : v) {
    double r = (*f)(s);
    res.push_back(r);
  }
  return res;
}

void print(vector<double>& vd) {
  for (const auto& d : vd)
    cout << d << " ";
  cout << '\n';
}

double double_size(Shape* ps) { return ps->size() * 2; }

auto triple_size = [](Shape* ps) { return ps->size() * 3; };

template<typename T>
class Nsize {
  const int nn;
public:
  Nsize(const int n) :nn{n} { }
  double operator()(T* ps) const { return ps->size() * nn; }
};

int main() {
  Shape s1 {2.3};
  Shape s2 {4.5};

  vector<Shape*> v;
  v.push_back(&s1);
  v.push_back(&s2);

  vector<double> v1 = apply(v, double_size);
  print(v1);

  vector<double> v2 = apply(v, triple_size);
  print(v2);

  Nsize<Shape> quad_size {4};
  cout << quad_size(&s1) << '\n';

  // TODO: how to specify apply's arguments to make this work?
  // vector<double> v3 = apply(v, quad_size);
}
