#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	int n;
	string s;
	set<string> a;
	cin >> n;
	while (n--)
	{
		cin >> s;
		a.insert(s);
	}
	cout << a.size();
}