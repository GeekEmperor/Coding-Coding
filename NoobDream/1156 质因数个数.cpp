#include <iostream>
using namespace std;
const int N = 100000+5;
int primes[N] = {0};
int main()
{
	for (int i = 2; i < N; ++i)
	{
		if (!primes[i])
			primes[++primes[0]] = i;
		for (int j = 1; j <= primes[0] && i * primes[j] < N; ++j)
		{
			primes[i * primes[j]] = 1;
			if (i % primes[j] == 0)
				break;
		}
	}
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int ans = 0;
		for (int i = 1; i <= primes[0] && i <= n; ++i)
		{
			while (n % primes[i] == 0)
			{
				n /= primes[i];
				++ans;
			}
		}
		if (n > 1)
			++ans;
		printf("%d\n", ans);
	}
}