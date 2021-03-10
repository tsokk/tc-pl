#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// return substrings of `s`, such that their size is at least
// `min` and at most `max`
map<string, vector<int>> subs(const string &s, int min, int max) {
  int n = s.size();
  map<string, vector<int>> subs;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      string x = s.substr(i, j - i);
      int m = x.size();
      if (min <= m && m <= max)
        subs[x];
    }
  }
  return subs;
}

// search for occurrences of substring `s` in string `s`;
// return the positions in which it is found
vector<int> search(size_t p, const string &s, const string &ss,
                   vector<int> &res) {
  size_t pos = ss.find(s, p);
  if (pos != string::npos) {
    res.push_back(pos);
    search(pos + 1, s, ss, res);
  }
  return res;
}

// return factors of integer n
vector<int> factors(int n) {
  vector<int> res;
  while (n % 2 == 0) {
    res.push_back(2);
    n /= 2;
  }
  for (int i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      res.push_back(i);
      n /= i;
    }
  }
  if (n > 2)
    res.push_back(n);
  return res;
}

int main() {
  ifstream ifs{"ciphertext"};
  string ss;
  getline(ifs, ss);
  // find all substrings of ss
  map<string, vector<int>> res = subs(ss, 2, 5);
  // find all positions in which each substring occur in ss
  for (auto &s : res) {
    vector<int> pos;
    search(0, s.first, ss, pos);
    res[s.first] = pos;
  }
  // write out all repetitions, their positions, intervals and
  // factors of the intervals; this is the Kasinski analysis
  map<int, int> freq;
  cout << "repetition" << '\t' << "first" << '\t' << "second" << '\t'
       << "interval" << '\t' << "factors" << '\n';
  for (const auto &r : res) {
    if (r.second.size() > 1) {
      int a{r.second[0]};
      int b{r.second[1]};
      vector<int> facts = factors(b - a);
      cout << r.first << "\t\t" << a << '\t' << b << '\t' << b - a << "\t\t";
      for (const auto &i : facts) {
        cout << i << '\t';
        auto search = freq.find(i);
        if (search != freq.end())
          search->second += 1;
        else
          freq.insert({i, 1});
      }
      cout << '\n';
    }
  }
	// write out the frequencies of factors
  cout << '\n'
			 << "Frequencies of the factors\n";
	for (const auto & f : freq)
		cout << f.first << '\t' << f.second << '\n';
}
