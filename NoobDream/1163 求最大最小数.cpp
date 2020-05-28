#include <iostream>
#include <climits>
using namespace std;
int main()
{
	int n, a;
	while (cin >> n)
	{
		int big = INT_MIN, small = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			if (a > big)
				big = a;
			if (a < small)
				small = a;
		}
		cout << big << ' ' << small << endl;
	}
}