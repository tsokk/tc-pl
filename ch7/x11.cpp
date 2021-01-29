#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool has_word(vector<string>& words, string& s)
{
	for (const auto& w : words)
		if (w==s)
			return true;
	return false;
}

void print(vector<string>& words)
{
	for (const auto& w : words)
		cout << w << '\n';
}

int main()
{
	vector<string> words;
	for (string w; cin>>w && w!="Quit"; )
		if (!has_word(words, w))
			words.push_back(w);
	print(words);
	sort(words.begin(),words.end());
	print(words);
}
