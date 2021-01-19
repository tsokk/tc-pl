#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(const vector<string>& vs)
{
	for (const auto& s : vs)
		cout << s << " ";
	cout << '\n';
}
	
int main()
{
	vector<string> vs {"Kant", "Plato", "Aristotle", "Kierkegaard", "Hume"};
	print_vector(vs);
	sort(vs.begin(),vs.end());
	print_vector(vs);
}