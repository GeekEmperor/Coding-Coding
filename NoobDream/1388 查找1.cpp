#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n, m, x;
	while (cin >> n)
	{
		set<int> s;
		while (n--)
		{
			cin >> x;
			s.insert(x);
		}
		cin >> m;
		while (m--)
		{
			cin >> x;
			if (s.count(x))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}