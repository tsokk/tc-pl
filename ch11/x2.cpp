#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <numeric>
#include <iterator>

// data structures and functions for profiling statistics
struct Result { const double sum; const long time; };
struct Statistic{ const double mean; const double sd; };

const double mean(const std::vector<double>& obs) {
  auto sum = std::accumulate(obs.begin(), obs.end(), 0);
  auto count = obs.size();
  return sum/count;
}

const double sd(const std::vector<double>& obs) {
  auto avg = mean(obs);
  auto n_1 = obs.size() - 1;
  double sum = 0;
  for (const auto& x : obs) {
    auto d = x - avg;
    sum += d * d;
  }
  return sqrt(sum/n_1);
}

// for loop using indices
template<typename T>
Result f1(const std::vector<T>& vi) {
  double sum = 0;
  const int n = vi.size();
  auto t0 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < n; ++i)
    sum += vi[i];
  auto t1 = std::chrono::high_resolution_clock::now();
  Result res = {sum, std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count()};
  return res;
}

// for loop using pointers
template<typename T>
Result f2(std::vector<T>& vi) {
  double sum = 0;
  auto t0 = std::chrono::high_resolution_clock::now();
  for (int* i = reinterpret_cast<int*>(&vi[0]); i != reinterpret_cast<int*>((&vi[0] + vi.size())); ++i)
    sum += *i;
  auto t1 = std::chrono::high_resolution_clock::now();
  Result res = {sum, std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count()};
  return res;
}

// for loop using iterators
template<typename T>
Result f3(const std::vector<T>& vi) {
  double sum = 0;
  auto t0 = std::chrono::high_resolution_clock::now();
  for (auto i = begin(vi); i != end(vi); ++i)
    sum += *i;
  auto t1 = std::chrono::high_resolution_clock::now();
  Result res = {sum, std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count()};
  return res;
}

// range-for
template<typename T>
Result f4(const std::vector<T>& vi) {
  double sum = 0;
  auto t0 = std::chrono::high_resolution_clock::now();
  for (const auto& i : vi)
    sum += i;
  auto t1 = std::chrono::high_resolution_clock::now();
  Result res = {sum, std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count()};
  return res;
}

// for_each algorithm
template<typename T>
Result f5(const std::vector<T>& vi) {
  double sum = 0;
  auto t0 = std::chrono::high_resolution_clock::now();
  std::for_each(vi.begin(), vi.end(), [&](int n) { sum += n; });
  auto t1 = std::chrono::high_resolution_clock::now();
  Result res = {sum, std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count()};
  return res;
}

// function object
template<typename T>
class Sum_elems {
  const std::vector<T>& vec;
public:
  Sum_elems(const std::vector<T>& v) :vec{v} { }
  double operator()() const {
    double sum = 0;
    for(const auto& elem : vec)
      sum += elem;
    return sum;
  }
};

// lambda function
template<typename T>
auto f7 = [](std::vector<T>& vd) {
  double sum = 0;
  for (const auto& d : vd)
    sum += d;
  return sum;
 };

Statistic measure(const std::vector<double>& vd) {
  auto sample_mean = mean(vd);
  auto sample_sd = sd(vd);
  return {sample_mean, std::round(sample_sd)};
}

template<typename T>
void profile_loops(std::vector<T>& a) {
  // for loop using indices
  const int n = 200;
  std::vector<double> v1;
  for (auto i = 0; i < n; ++i) {
    double dur = f1(a).time;
    v1.push_back(dur);
  }
  Statistic s1 = measure(v1);
  std::cout << "for loop with indices (us): " << "mean = " << s1.mean << ", sd = " << s1.sd << '\n';

  // for loop using pointers
  std::vector<double> v2;
  for (auto i = 0; i < n; ++i) {
    double dur = f2(a).time;
    v2.push_back(dur);
  }
  Statistic s2 = measure(v2);
  std::cout << "for loop with pointers (us): " << "mean = " << s2.mean << ", sd = " << s2.sd << '\n';

  // for loop using iterators
  std::vector<double> v3;
  for (auto i = 0; i < n; ++i) {
    double dur = f3(a).time;
    v3.push_back(dur);
  }
  Statistic s3 = measure(v3);
  std::cout << "for loop with iterators (us): " << "mean = " << s3.mean << ", sd = " << s3.sd << '\n';

  // range-for loop
  std::vector<double> v4;
  for (auto i = 0; i < n; ++i) {
    double dur = f4(a).time;
    v4.push_back(dur);
  }
  Statistic s4 = measure(v4);
  std::cout << "range-for loop (us): " << "mean = " << s4.mean << ", sd = " << s4.sd << '\n';

  // for_each algorithm
  std::vector<double> v5;
  for (auto i = 0; i < n; ++i) {
    double dur = f5(a).time;
    v5.push_back(dur);
  }
  Statistic s5 = measure(v5);
  std::cout << "for_each algorithm (us): " << "mean = " << s5.mean << ", sd = " << s5.sd << '\n';
}

int main() {
  const int n = 200;
  // Element type integer
  std::vector<int> a;
  for (int i = 0; i < 1e5; ++i)
    a.push_back(i);

  // loops of different kinds
  std::cout << "Summing 100 000 ints, using\n";
  profile_loops(a);

  // and the function object
  std::vector<double> v6;
  for (auto i = 0; i < n; ++i) {
    auto t0 = std::chrono::high_resolution_clock::now();
    Sum_elems<int> sum {a};
    sum();
    auto t1 = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count();
    v6.push_back(dur);
  }
  Statistic s6 = measure(v6);
  std::cout << "function object (us): " << "mean = " << s6.mean << ", sd = " << s6.sd << '\n';

  // and the lambda function
  std::vector<double> v7;
  for (auto i = 0; i < n; ++i) {
    auto t0 = std::chrono::high_resolution_clock::now();
    f7<int>(a);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count();
    v7.push_back(dur);
  }
  Statistic s7 = measure(v7);
  std::cout << "lambda function (us): " << "mean = " << s7.mean << ", sd = " << s7.sd << '\n';

  // Element type double
  std::vector<double> b;
  for (int i = 0; i < 1e5; ++i)
    b.push_back(i);

  std::cout << '\n';
  std::cout << "Summing 100 000 doubles, using\n";
  profile_loops(b);

  // and the function object
  std::vector<double> v8;
  for (auto i = 0; i < n; ++i) {
    auto t0 = std::chrono::high_resolution_clock::now();
    Sum_elems<double> sum {b};
    sum();
    auto t1 = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count();
    v8.push_back(dur);
  }
  Statistic s8 = measure(v8);
  std::cout << "function object (us): " << "mean = " << s8.mean << ", sd = " << s8.sd << '\n';

  // and the lambda function
  std::vector<double> v9;
  for (auto i = 0; i < n; ++i) {
    auto t0 = std::chrono::high_resolution_clock::now();
    f7<double>(b);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count();
    v9.push_back(dur);
  }
  Statistic s9 = measure(v9);
  std::cout << "lambda function (us): " << "mean = " << s9.mean << ", sd = " << s9.sd << '\n';

  /* Output of this program:
    Summing 100 000 ints, using
    for loop with indices (us): mean = 323, sd = 18
    for loop with pointers (us): mean = 491, sd = 25
    for loop with iterators (us): mean = 2071, sd = 42
    range-for loop (us): mean = 1178, sd = 36
    for_each algorithm (us): mean = 1347, sd = 28
    function object (us): mean = 1200, sd = 25
    lambda function (us): mean = 1192, sd = 25

    Summing 100 000 doubles, using
    for loop with indices (us): mean = 302, sd = 14
    for loop with pointers (us): mean = 936, sd = 20
    for loop with iterators (us): mean = 2043, sd = 39
    range-for loop (us): mean = 1139, sd = 25
    for_each algorithm (us): mean = 1409, sd = 33
    function object (us): mean = 1191, sd = 55
    lambda function (us): mean = 1178, sd = 24
  */
}
