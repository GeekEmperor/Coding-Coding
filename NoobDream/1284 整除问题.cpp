#include <iostream>
using namespace std;
void compute(int N, int primes[])
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
}
void decomp(int n, int counts[], int primes[])
{
	for (int j = 1; j <= primes[0] && j <= n; ++j)
	{
		while (n % primes[j] == 0)
		{
			n /= primes[j];
			++counts[primes[j]];
		}
	}
}
int main()
{
	const int N = 1005;
	int primes[N] = { 0 };
	compute(N, primes);
	int n, a, t;
	cin >> n >> a;
	int counts1[N] = { 0 };
	for (int i = 1; i <= n; ++i)
		decomp(i, counts1, primes);
	int counts2[N] = { 0 };
	decomp(a, counts2, primes);
	int k = 1000;
	for (int i = 1; i <= N; ++i)
	{
		if (counts2[i] && counts1[i] / counts2[i] < k)
			k = counts1[i] / counts2[i];
	}
	cout << k;
}