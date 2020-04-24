#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> d(n);
		for (int i = 0; i < n; ++i)
			cin >> d[i];
		sort(d.begin(), d.end());
		int ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (gcd(d[j], d[i]) == 1)
					++ans;
		cout << ans << endl;
	}
}