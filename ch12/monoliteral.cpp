#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  string s;
  getline(cin, s);

  map<char, int> mono;
  for (const auto &c : s) {
    auto search = mono.find(c);
    if (search != mono.end())
      mono[c] += 1;
    else
      mono[c] = 1;
  }

  vector<pair<int, char>> freq;
  for (const auto &m : mono)
    freq.push_back(make_pair(m.second, m.first));

  sort(freq.begin(), freq.end(),
            [](const pair<int, char> &a, const pair<int, char> &b) {
              return a.first > b.first;
            });

	cout << "char" << "\t" << "freq\n";
  for (const auto &f : freq)
    cout << f.second << '\t' << f.first << '\n';
}
