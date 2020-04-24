#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp0(const pair<int, string>& a, const pair<int, string>& b)
{
	return a.first > b.first;
}
bool cmp1(const pair<int, string>& a, const pair<int, string>& b)
{
	return a.first < b.first;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, string>> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].second >> v[i].first;
	if (m == 0)
		stable_sort(v.begin(), v.end(), cmp0);
	else
		stable_sort(v.begin(), v.end(), cmp1);
	for (int i = 0; i < n; ++i)
		cout << v[i].second << ' ' << v[i].first << endl;
}