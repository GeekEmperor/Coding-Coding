#include <iostream>
using namespace std;
int main()
{
	int t, a, b, c, s;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> a >> b >> c;
		s = a + b;
		if (a > 0 && b > 0 && s < 0)
			cout << "Case #" << i + 1 << ": true\n";
		else if (a < 0 && b < 0 && s > 0)
			cout << "Case #" << i + 1 << ": false\n";
		else if (s > c)
			cout << "Case #" << i + 1 << ": true\n";
		else
			cout << "Case #" << i + 1 << ": false\n";
	}
	return 0;
}