#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int a, b, d;
	cin >> a >> b >> d;
	int c = a + b;
	string s;
	while (c)
	{
		s += c % d + '0';
		c /= d;
	}
	reverse(s.begin(), s.end());
	if (s.empty())
		s = "0";
	cout << s;
	return 0;
}