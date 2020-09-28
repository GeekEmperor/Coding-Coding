#include <iostream>
using namespace std;
int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		while (x != y)
			if (x > y)
				x >>= 1;
			else
				y >>= 1;
		cout << x << endl;
	}
}