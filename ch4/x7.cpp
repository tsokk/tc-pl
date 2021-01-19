#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(const vector<int>& vi)
{
	for (const auto& i : vi)
		cout << i << " ";
	cout << '\n';
}
	
int main()
{
	vector<int> vi {5,9,-1,200,0};
	print_vector(vi);
	sort(vi.begin(),vi.end());
	print_vector(vi);
}