#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string p, s;
		cin >> p >> s;
		vector<int> next(p.size() + 1);
		next[0] = -1;
		int i = 0, j = -1, count = 0;
		while (i < p.size())
		{
			if (j == -1 || p[i] == p[j])
				next[++i] = ++j;
			else
				j = next[j];
		}
		i = 0, j = 0;
		while (i < s.size())
		{
			if (j == -1 || s[i] == p[j])
				++i, ++j;
			else
				j = next[j];
			if (j >= (int)p.size())
			{
				++count;
				j = next[j];
			}
		}
		cout << count << endl;
	}
	return 0;
}
