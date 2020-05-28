#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool check(string s)
{
	stack<char> st;
	for (char c : s)
	{
		if (c == '(' || c == '[')
			st.push(c);
		else if (st.empty() || c - st.top() > 2 || c - st.top() < 1)
			return false;
		else
			st.pop();
	}
	return st.empty();
}
int main()
{
	string s;
	cin >> s;
	cout << (check(s) ? "YES" : "NO");
}