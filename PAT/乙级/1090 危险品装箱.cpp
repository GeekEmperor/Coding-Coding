#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> objs;
	int x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		objs.emplace_back(x, y);
	}
	int k;
	for (int i = 0; i < m; ++i)
	{
		cin >> k;
		vector<int> box(k);
		for (int j = 0; j < k; ++j)
			cin >> box[j];
		for (k = 0; k < n; ++k)
			if (find(box.begin(), box.end(), objs[k].first) != box.end() &&
				find(box.begin(), box.end(), objs[k].second) != box.end())
			{
				cout << "No\n";
				break;
			}
		if (k == n)
			cout << "Yes\n";
	}
	return 0;
}