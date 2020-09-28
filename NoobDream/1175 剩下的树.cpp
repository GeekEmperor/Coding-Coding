#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
	int l, m, b, e;
	while (cin >> l >> m)
	{
		vector<bool> a(l + 1, true);
		while (m--)
		{
			cin >> b >> e;
			while (b <= e)
				a[b++] = false;
		}
		cout << accumulate(a.begin(), a.end(), 0) << endl;
	}
}