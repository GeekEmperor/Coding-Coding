#include <iostream>
using namespace std;
int main()
{
	unsigned short a, b;
	while (cin >> a >> b)
	{
		int i;
		for (i = 0; i < 16; ++i)
		{
			if (a == b)
			{
				cout << "YES\n";
				break;
			}
			a = (a << 1) | (a >> 15);
		}
		if (i >= 16)
			cout << "NO\n";
	}
}