#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, a, b, c, d, m, root;
	cin >> n;
	vector<vector<int>> tree(200, vector<int>(4, -1));
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c >> d;
		if (!i) root = a;
		tree[a][1] = b;
		tree[a][2] = c;
		tree[a][3] = d;
		if (b != -1) tree[b][0] = a;
		if (c != -1) tree[c][0] = a;
		if (d != -1) tree[d][0] = a;
	}
	cin >> m;
	vector<pair<int, int>> order(m);
	for (int i = 0; i < m; ++i)
		cin >> order[i].second >> order[i].first;
	sort(order.begin(), order.end());
	vector<int> last = { root };
	for (int i = 0; i < m; ++i)
	{
		vector<int> current;
		int j = order[i].second;
		while (j != root)
		{
			j = tree[j][0];
			current.push_back(j);
		}
		for (j = 0; j < last.size(); ++j)
		{
			if (find(current.begin(), current.end(), last[j]) != current.end())
			{
				for (j = find(current.begin(), current.end(), last[j])
					- current.begin(); j >= 0; --j)
					cout << current[j] << ' ';
				break;
			}
			else
				cout << last[j] << ' ';
		}
		cout << order[i].second << endl;
		last = current;
	}
	for (int i = 0; i < last.size(); ++i)
		cout << last[i] << ' ';
	cout << endl;
}