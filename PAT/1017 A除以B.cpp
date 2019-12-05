#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a;
	int b;
	cin >> a >> b;
	string q;
	int p, r = 0;
	for (char c : a)
	{
		p = r * 10 + c - '0';
		q += p / b + '0';
		r = p % b;
	}
	while (q.size() > 1 && q[0] == '0')
		q.erase(q.begin());
	cout << q << ' ' << r;
	return 0;
}