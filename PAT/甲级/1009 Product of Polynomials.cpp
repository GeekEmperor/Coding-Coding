#include <iostream>
using namespace std;
int main()
{
	int k, n = 0;
	float a[1001] = { 0 }, b[1001] = { 0 }, c[2001] = { 0 };
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &n);
		scanf("%f", &a[n]);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &n);
		scanf("%f", &b[n]);
	}
	for (int i = 0; i < 1001; ++i)
		for (int j = 0; j < 1001; ++j)
			c[i + j] += a[i] * b[j];
	int count = 0;
	for (int i = 0; i < 2001; ++i)
		if (c[i])
			++count;
	printf("%d", count);
	for (int i = 2000; i >= 0; --i)
		if (c[i])
			printf(" %d %.1f%", i, c[i]);
	return 0;
}