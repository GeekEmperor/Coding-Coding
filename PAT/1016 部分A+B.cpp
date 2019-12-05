#include <iostream>
using namespace std;
int main()
{
	int a, da, b, db;
	cin >> a >> da >> b >> db;
	int pa = 0, pb = 0;
	while (a)
	{
		if (a % 10 == da)
		{
			pa *= 10;
			pa += da;
		}
		a /= 10;
	}
	while (b)
	{
		if (b % 10 == db)
		{
			pb *= 10;
			pb += db;
		}
		b /= 10;
	}
	cout << pa + pb;
	return 0;
}