#include <iostream>
using namespace std;
bool isprime(int n)
{
	if (n > 2 && (n & 1) == 0)
		return false;
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return n > 1;
}
int main()
{
	int m, n;
	cin >> m >> n;
	int count = 1;
	int i = 2, j = 1;
	for (; j < m; ++i)
		if (isprime(i))
			++j;
	for (; j < n; ++i)
		if (isprime(i))
		{
			if (count == 10)
			{
				cout << i << '\n';
				count = 1;
			}
			else
			{
				cout << i << ' ';
				++count;
			}
			++j;
		}
	for (; j == n; ++i)
		if (isprime(i))
		{
			if (count == 10)
				cout << i << '\n';
			else
				cout << i;
			++j;
		}
	return 0;
}