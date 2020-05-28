#include <iostream>
using namespace std;
int a[1000001] = {0, 1, 2};
int main()
{
	for (int i = 3; i < 1000001; ++i)
		if (i & 1)
			a[i] = a[i - 1];
		else
			a[i] = (a[i - 1] + a[i >> 1]) % 1000000000;
	int n;
	while (cin >> n)
		cout << a[n] << endl;
}