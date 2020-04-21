#include <iostream>
#include <string>
using namespace std;
bool isprime(int n)
{
	if (n > 2 && n % 2 == 0)
		return false;
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return n > 1;
}
int main()
{
	int n;
	cin >> n;
	bool x = false, y = false;
	int m = 0;
	for (int i = 3; i <= n; i += 2)
	{
		y = isprime(i);
		if (x && y)
			++m;
		x = y;
	}
	cout << m;
	return 0;
}