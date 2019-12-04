#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		char str[100];
		cin >> str;
		int i = 0, x = 0, y = 0, z = 0;
		while (str[i] == 'A')
			++i, ++x;
		if (str[i++] != 'P')
		{
			cout << "NO\n";
			continue;
		}
		while (str[i] == 'A')
			++i, ++y;
		if (str[i++] != 'T')
		{
			cout << "NO\n";
			continue;
		}
		while (str[i] == 'A')
			++i, ++z;
		if (i >= strlen(str) && y > 0 && z == x * y)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}