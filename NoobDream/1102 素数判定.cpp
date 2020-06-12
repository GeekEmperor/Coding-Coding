#include <iostream>
using namespace std;
int main()
{
	int primes[1001] = { 0 };
	for (int i = 2; i <= 1000; ++i)
	{
		if (!primes[i])
			primes[++primes[0]] = i;
		for (int j = 1; j <= primes[0] && primes[j] * i <= 1000; ++j)
		{
			primes[primes[j] * i] = 1;
			if (i % primes[j] == 0)
				break;
		}
	}
	int a, b;
	while (cin >> a >> b)
	{
		if (a > b)
			swap(a, b);
		int ans = 0;
		for (int i = 1; primes[i] <= b; ++i)
			if (primes[i] >= a)
				++ans;
		cout << ans << endl;
	}
}