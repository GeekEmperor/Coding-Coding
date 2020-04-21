#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	char courses[4] = { 'A','C','M','E' };
	vector<pair<int, vector<float>>> data(n);
	for (int i = 0; i < n; ++i)
	{
		int id, c, m, e;
		cin >> id >> c >> m >> e;
		float a = (c + m + e) / 3.0;
		data[i] = { id, {a, float(c), float(m), float(e)} };
	}
	for (int i = 0; i < m; ++i)
	{
		int id;
		cin >> id;
		auto it = find_if(data.begin(), data.end(), [=](auto& s) {return s.first == id; });
		if (it == data.end())
			cout << "N/A\n";
		else
		{
			int idx = 0, best = n + 1;
			for (int j = 0; j < 4; ++j)
			{
				int rank = 1;
				for (int k = 0; k < n; ++k)
					if (data[k].second[j] > it->second[j])
						++rank;
				if (rank < best)
				{
					best = rank;
					idx = j;
				}
			}
			cout << best << ' ' << courses[idx] << endl;
		}
	}
	return 0;
}