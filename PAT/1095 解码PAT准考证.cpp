#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void solve1(vector<pair<string, int>>& data, string& s)
{
	vector<pair<string, int>> temp;
	for (auto& p : data)
		if (p.first[0] == s[0])
			temp.emplace_back(p);
	sort(temp.begin(), temp.end(), [](auto& a, auto& b) {return a.second > b.second || (a.second == b.second && a.first < b.first); });
	if (temp.empty())
		cout << "NA\n";
	for (auto& p : temp)
		printf("%s %d\n", p.first.c_str(), p.second);
}
void solve2(vector<pair<string, int>>& data, string& s)
{
	int count = 0, grade = 0;
	for (auto& p : data)
		if (p.first.substr(1, 3) == s)
		{
			++count;
			grade += p.second;
		}
	if (!count)
		cout << "NA\n";
	else
		cout << count << " " << grade << endl;
}
void solve3(vector<pair<string, int>>& data, string& s)
{
	map<int, int> dict;
	for (auto& p : data)
		if (p.first.substr(4, 6) == s)
			++dict[stoi(p.first.substr(1, 3))];
	vector<pair<int, int>> temp(dict.begin(), dict.end());
	sort(temp.begin(), temp.end(), [](auto& a, auto& b) {return a.second > b.second || (a.second == b.second && a.first < b.first); });
	if (temp.empty())
		cout << "NA\n";
	for (auto& p : temp)
		printf("%d %d\n", p.first, p.second);
}
int main()
{
	int n, m, t;
	string s;
	cin >> n >> m;
	vector<pair<string, int>> data(n);
	for (int i = 0; i < n; ++i)
		cin >> data[i].first >> data[i].second;
	for (int i = 0; i < m; ++i) 
	{
		cin >> t >> s;
		printf("Case %d: %d %s\n", i + 1, t, s.c_str());
		switch (t) 
		{
		case 1:
			solve1(data, s);
			break;
		case 2:
			solve2(data, s);
			break;
		case 3:
			solve3(data, s);
			break;
		default:
			cout << "NA\n";
			break;
		}
	}
	return 0;
}