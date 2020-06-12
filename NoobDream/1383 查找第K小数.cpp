#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	int n, k, x;
	while (cin >> n)
	{
		set<int> a;
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			a.insert(x);
		}
		cin >> k;
		vector<int> b(a.begin(), a.end());
		nth_element(b.begin(), b.begin() + k - 1, b.end());
		cout << b[k - 1] << endl;
	}
}