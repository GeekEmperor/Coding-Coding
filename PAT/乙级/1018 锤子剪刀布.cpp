#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char x, y;
	int a[3] = { 0 }, b[3] = { 0 }, c[3] = { 0 };
	while (n--)
	{
		cin >> x >> y;
		if (x == y)
			++c[1];
		else if (x == 'C' && y == 'J' || x == 'J' && y == 'B' || x == 'B' && y == 'C')
		{
			++c[0];
			if (x == 'C')
				++a[0];
			else if (x == 'J')
				++a[1];
			else
				++a[2];
		}
		else
		{
			++c[2];
			if (y == 'C')
				++b[0];
			else if (y == 'J')
				++b[1];
			else
				++b[2];
		}
	}
	cout << c[0] << ' ' << c[1] << ' ' << c[2] << endl;
	cout << c[2] << ' ' << c[1] << ' ' << c[0] << endl;
	if (a[2] >= a[1] && a[2] >= a[0])
		cout << 'B';
	else if (a[0] >= a[1] && a[0] >= a[2])
		cout << 'C';
	else
		cout << 'J';
	cout << ' ';
	if (b[2] >= b[1] && b[2] >= b[0])
		cout << 'B';
	else if (b[0] >= b[1] && b[0] >= b[2])
		cout << 'C';
	else
		cout << 'J';
	return 0;
}