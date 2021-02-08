#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Entry {
  string name;
  double value;
};

istream &operator>>(istream &is, Entry &e) {
  string name;
  double value;
  cin >> name >> value;

  if (name != "" && value > 0) {
    e = {name, value};
    return is;
  }
  is.setstate(ios_base::failbit);
  return is;
}

int main() {
  map<string, double> sum;
  map<string, double> count;

  double sum_all = 0;
  double count_all = 0;
  for (Entry e; cin >> e;) {
    sum[e.name] += e.value;
    count[e.name] += 1;
    sum_all += e.value;
    count_all +=  1;
  }

  map<string, double> average;
  for (const auto& c : count) {
    average[c.first] = sum.find(c.first)->second/c.second;
  }

  cout << "name\t" << "mean" << '\n';
  for (const auto& a :  average)
    cout << a.first << '\t' << a.second <<  '\n';
  
  cout << "sum (all): " << sum_all << ", " << "mean (all): " 
    << sum_all/count_all << '\n';
}
