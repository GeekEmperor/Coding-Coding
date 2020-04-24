#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, c;
	scanf("%d%d", &n, &c);
	int* v = new int[n + 1];
	for (int i = 0; i < n; ++i)
		scanf("%d%", v + i);
	v[n] = 0x7fffffff;
	sort(v, v + n);
	int ans = 0;
	for (int i = 0; i < n; ++i
		ans += lower_bound(v, v + n, v[i] + c + 1) - v
			- (lower_bound(v, v + n, v[i] + c) - v);
	cout << ans;
	delete[] v;
}