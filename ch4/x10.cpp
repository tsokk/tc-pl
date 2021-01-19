#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
	
int main()
{
	ifstream ifs {"x9.txt"};
	vector<int> vi;
	for (int i; ifs>>i; )
		vi.push_back(i);
	cout << "read " << vi.size() << " integers\n";
}
