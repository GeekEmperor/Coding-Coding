#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int eliminate(string& s)
{
	string t;
	for (int i = 0; i < s.size(); ++i)
		if ((i == 0 || s[i] != s[i - 1]) && s[i] != s[i + 1])
			t += s[i];
	return s.size() == t.size() ? t.size() : eliminate(t);
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		int m = 0;
		for (int i = 0; i <= s.size(); ++i)
			for (char c = 'A'; c <= 'C'; ++c)
			{
				string t = s;
				t.insert(i, 1, c);
				m = max(m, (int)t.size() - eliminate(t));
			}
		cout << m << endl;
	}
	return 0;
}
