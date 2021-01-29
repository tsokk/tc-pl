#include <iostream>
#include <string>

using namespace std;

int scount(string& s, string& word)
{
	int res = 0;
	size_t pos = 0;
	while ((pos = word.find(s, pos))!=string::npos) {
		++res;
		++pos;
	}
	return res;
}

int scount(string&s, char* c)
{
	int res = 0;
	while ((*c)!='\0') {
		if (*c==s[0] && (*(c+1))==s[1])
			++res;
		++c;
	}
	return res;
}

int main()
{
	string word {"xabaacbaxabb"};
	string s {"ab"};
	cout << scount(s,word) << '\n'; // writes 2
	char aword[] = "xabaacbaxabb\0";
	cout << scount(s,aword) << '\n'; // writes 2
}

