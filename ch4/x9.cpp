#include <fstream>

using namespace std;
	
int main()
{
	ofstream ofs {"x9.txt"};
	for (int i {1}; i<=300; ++i)
		ofs << i << " ";
}
