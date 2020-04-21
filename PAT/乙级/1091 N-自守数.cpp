#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int m, k;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> k;
		int c = 0;
		if (k < 10)
			c = 1;
		else if (k < 100)
			c = 2;
		else if (k < 1000)
			c = 3;
		else
			c = 4;
		int n = 1;
		for (; n < 10; ++n)
		{
			if (n * k * k % (int)pow(10, c) == k)
			{
				cout << n << ' ' << n * k * k << endl;
				break;
			}
		}
		if (n == 10)
			cout << "No\n";
	}
	return 0;
}