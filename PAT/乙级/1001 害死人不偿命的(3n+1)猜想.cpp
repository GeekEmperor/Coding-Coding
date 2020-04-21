#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int m = 0;
	while (n != 1)
	{
		if (n & 1)
			n = (3 * n + 1) >> 1;
		else
			n >>= 1;
		++m;
	}
	cout << m;
	return 0;
}