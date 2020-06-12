#include <iostream>
using namespace std;
int main()
{
	int primes[10001] = { 0 };
	for (int i = 2; i <= 10000; ++i)
	{
		if (!primes[i])
			primes[++primes[0]] = i;
		for (int j = 1; j <= primes[0] && i * primes[j] <= 10000; ++j)
		{
			primes[i * primes[j]] = 1;
			if (i % primes[j] == 0)
				break;
		}
	}
	int ones[1000] = { 0 };
	for (int i = 1, j = 0; i <= primes[0]; ++i)
		if (primes[i] % 10 == 1)
			ones[j++] = primes[i];
	int n;
	while (cin >> n)
	{
		bool flag = false;
		for (int i = 0; ones[i] <= n; ++i)
		{
			flag = true;
			cout << ones[i] << ' ';
		}
		if (!flag)
			cout << -1;
		cout << endl;
	}
}