#include <iostream>
using namespace std;
int main()
{
	int a, n, x = 0, s = 0;
	cin >> a >> n;
	for (int i = 0; i < n; ++i)
	{
		x *= 10;
		x += a;
		s += x;
	}
	cout << s;
}