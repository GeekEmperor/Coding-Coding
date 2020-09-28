#include <iostream>
using namespace std;
int main()
{
	int a[200001] = { 0 };
	int b, e;
	while (scanf("%d%d", &b, &e) != EOF && (b || e))
		++a[b], --a[e + 1];
	for (int i = 1; i < 200001; ++i)
		a[i] += a[i - 1];
	while (scanf("%d%d", &b, &e) != EOF && (b || e))
		while (b <= e)
			printf("%d\n", a[b++]);
}