#include <iostream>
#include <string>
using namespace std;
void dfs(string& s, string& t, int i)
{
	int n = s.size();
	if (i >= n)
	{
		cout << t << endl;
		return;
	}
	for (int j = 0; j < n; ++j)
	{
		if (t.find(s[j]) != -1)
			continue;
		t.push_back(s[j]);
		dfs(s, t, i + 1);
		t.pop_back();
	}
}
int main()
{
	string s, t;
	cin >> s;
	dfs(s, t, 0);
}