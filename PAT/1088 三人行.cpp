#include <iostream>
#include <cmath>
using namespace std;
string check(int m, float n)
{
	if (m < n)
		return " Cong";
	else if (m > n)
		return " Gai";
	else
		return " Ping";
}
int main()
{
	int m, x, y;
	cin >> m >> x >> y;
	for (int s = 9; s > 0; --s)
		for (int t = 9; t >= 0; --t)
			if (y * abs(9 * s - 9 * t) == x * (s + 10 * t))
			{
				int a = 10 * s + t;
				int b = 10 * t + s;
				float c = 1.0 * b / y;
				cout << a << check(m, a) << check(m, b) << check(m, c);
				return 0;
			}
	cout << "No Solution";
	return 0;
}