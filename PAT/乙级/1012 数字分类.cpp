#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n;
	vector<vector<int>> bucket(5);
	for (int i = 0; i < n; ++i)
	{
		cin >> m;
		bucket[m % 5].emplace_back(m);
	}
	int s = 0;
	for (int i = 0; i < bucket[0].size(); ++i)
		if ((bucket[0][i] & 1) == 0)
			s += bucket[0][i];
	if (s)
		cout << s;
	else
		cout << 'N';
	cout << ' ';
	s = 0;
	for (int i = 0; i < bucket[1].size(); i += 2)
		s += bucket[1][i];
	for (int i = 1; i < bucket[1].size(); i += 2)
		s -= bucket[1][i];
	if (bucket[1].empty())
		cout << 'N';
	else
		cout << s;
	cout << ' ';
	if (bucket[2].empty())
		cout << 'N';
	else
		cout << bucket[2].size();
	cout << ' ';
	s = 0;
	for (int i = 0; i < bucket[3].size(); ++i)
		s += bucket[3][i];
	if (bucket[3].empty())
		cout << 'N';
	else
		cout << fixed << setprecision(1) << float(s) / bucket[3].size();
	cout << ' ';
	if (bucket[4].empty())
		cout << 'N';
	else
		cout << *max_element(bucket[4].begin(), bucket[4].end());
	return 0;
}