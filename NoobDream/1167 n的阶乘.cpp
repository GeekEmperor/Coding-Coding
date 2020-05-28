#include <iostream>
using namespace std;
int main()
{
	long long fac[21];
	fac[0] = 1;
	for (int i = 1; i <= 20; ++i)
		fac[i] = fac[i - 1] * i;
	int n;
	while (cin >> n)
		cout << fac[n] << endl;
}