#include <iostream>
using namespace std;
int factor(int n)
{
	int ans = 1;
	for (int i = 2; i <= n; ++i)
	{
		int j = 0;
		while (n % i == 0)
		{
			n /= i;
			++j;
		}
		ans *= (j + 1);
	}
	return ans;
}
int main()
{
	int n;
	while (cin >> n && n)
	{
		int num;
		while (n--)
		{
			scanf("%d", &num);
			printf("%d\n", factor(num));
		}
	}
}