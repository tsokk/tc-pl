#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Entry {
	string name;
	int age;
};

ostream& operator<<(ostream& os, const Entry& e)
{
	return os << e.name << " " << e.age << '\n';
}

istream& operator>>(istream& is, Entry& e)
{
	string name;
	int age;
	is >> name >> age;
	if (name!="" && age!=0) {
		e = {name, age};
		return is;
	}
	is.setstate(ios_base::failbit);
	return is;
}

int main()
{
	vector<Entry> ve;
	for (Entry e; cin>>e; )
		ve.push_back(e);

	for (Entry e : ve)
		cout << e.name << " " << e.age << '\n';
}
