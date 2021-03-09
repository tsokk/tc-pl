#include <cmath>
#include <cstdlib>
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
vector<int> &search(size_t p, const string &s, const string &ss,
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
  int d = 2;
	int max = n;
  div_t p = div(n, d);
  if (p.rem == 0)
    res.push_back(d);
  d = 3;
  while (d <= max) {
    p = div(n, d);
    if (p.rem == 0) {
      res.push_back(d);
			n = p.quot;
			for (;;) {
				p = div(n, d);
				if (p.rem != 0)
					break;
				res.push_back(d);
				n = p.quot;
			}
		}
    d += 2;
  }
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
  // factors of the intervals
  cout << "repetition" << '\t' << "first" << '\t' << "second" << '\t'
       << "interval" << '\n';
  for (const auto &r : res) {
    if (r.second.size() > 1) {
      int a{r.second[0]};
      int b{r.second[1]};
      vector<int> facts = factors(b - a);
      cout << r.first << "\t\t" << a << '\t' << b << '\t' << b - a << '\t';
      for (const auto &i : facts)
        cout << i << '\t';
      cout << '\n';
    }
  }
}
