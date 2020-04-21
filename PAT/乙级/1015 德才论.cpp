#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stu
{
	int num, de, cai;
	stu(int n, int d, int c) { num = n, de = d, cai = c; }
	bool operator<(stu& s)
	{ 
		return de + cai > s.de + s.cai
			|| (de + cai == s.de + s.cai && de > s.de)
			|| (de + cai == s.de + s.cai && de == s.de && num < s.num);
	}
};
int main()
{
	int n, l, h;
	cin >> n >> l >> h;
	vector<vector<stu>> arr(4);
	int num, de, cai;
	for (int i = 0; i < n; ++i)
	{
		cin >> num >> de >> cai;
		if (de < l || cai < l)
			continue;
		else if (de >= h && cai >= h)
			arr[0].emplace_back(num, de, cai);
		else if (de >= h)
			arr[1].emplace_back(num, de, cai);
		else if (de >= cai)
			arr[2].emplace_back(num, de, cai);
		else
			arr[3].emplace_back(num, de, cai);
	}
	cout << arr[0].size() + arr[1].size() + arr[2].size() + arr[3].size() << endl;
	for (int i = 0; i < 4; ++i)
	{
		sort(arr[i].begin(), arr[i].end());
		for (stu& s : arr[i])
			cout << s.num << ' ' << s.de << ' ' << s.cai << endl;
	}
	return 0;
}