#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<long long> s(n);
		for (int i = 0; i < n; ++i)
			scanf("%lld", &s[i]);
		long long t = 0, ans = s[0];
		for (int i = 0; i < n; ++i)
		{
			t += s[i];
			if (t > ans)
				ans = t;
			if (t < 0)
				t = 0;
		}
		printf("%lld\n", ans);
	}
}