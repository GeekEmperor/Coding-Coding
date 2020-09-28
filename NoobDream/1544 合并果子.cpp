#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, x, y, ans = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	make_heap(a.begin(), a.end(), greater<int>());
	while (a.size() > 1)
	{
		pop_heap(a.begin(), a.end(), greater<int>());
		x = a.back();
		a.pop_back();
		pop_heap(a.begin(), a.end(), greater<int>());
		y = a.back();
		a.pop_back();
		ans += x + y;
		a.push_back(x + y);
		push_heap(a.begin(), a.end(), greater<int>());
	}
	cout << ans;
}