#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Drink
{
	int m, w;
	float r;
	Drink(int _m, int _w)
	{
		m = _m;
		w = _w;
		r = float(m) / w;
	}
	bool operator<(const Drink& d)
	{
		return r > d.r;
	}
};
int main()
{
	int x, n, m, w;
	while (cin >> x >> n)
	{
		if (x == -1 && n == -1)
			break;
		vector<Drink> a;
		for (int i = 0; i < n; ++i)
		{
			cin >> m >> w;
			a.emplace_back(m, w);
		}
		sort(a.begin(), a.end());
		float total = 0;
		for (int i = 0; i < n; ++i)
		{
			if (x >= a[i].w)
			{
				x -= a[i].w;
				total += a[i].m;
			}
			else
			{
				total += x * a[i].r;
				break;
			}
		}
		cout.setf(ios::fixed);
		cout.precision(3);
		cout << total << endl;
	}
}