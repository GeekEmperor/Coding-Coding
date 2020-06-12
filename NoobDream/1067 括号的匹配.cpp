#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool ismatch(string s)
{
	int priority[128] = { 0 };
	priority['{'] = 1, priority['}'] = 2;
	priority['['] = 3, priority[']'] = 4;
	priority['('] = 5, priority[')'] = 6;
	priority['<'] = 7, priority['>'] = 8;
	stack<char> st;
	for (char c : s)
	{
		if (priority[c] & 1)
		{
			if (st.empty() || priority[c] >= priority[st.top()])
				st.push(c);
			else
				return false;
		}
		else
		{
			if (!st.empty() && priority[c] == priority[st.top()] + 1)
				st.pop();
			else
				return false;
		}
	}
	return st.empty();
}
int main()
{
	int n;
	string s;
	cin >> n;
	while (n--)
	{
		cin >> s;
		cout << (ismatch(s) ? "YES\n" : "NO\n");
	}
}