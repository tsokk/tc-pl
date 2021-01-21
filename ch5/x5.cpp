#include <iostream>
#include <regex>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream ifs {"x5.txt"};
	smatch matches;
	regex pat {R"((-?\d+\.\d+))"};
	string line;
	int lineno = 0;
	while (getline(ifs,line)) {
		++lineno;
		vector<string> vs;
		size_t pos = 0;
		while (regex_search(line,matches,pat) && matches[0].matched) {
			string d = matches[1];
			pos = line.find(d)+d.size();
			vs.push_back(d);
			line = line.substr(pos, line.size()-pos);
		}
		if (vs.size())
			for (int i=0; i<vs.size(); ++i)
				cout << vs[i] << " ";
	}
	cout << '\n';
}

