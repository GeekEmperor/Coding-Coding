#include <iostream>
using namespace std;
long long power(int x, int n)
{
	if (n == 1)
		return x;
	long long ans = power(x, n >> 1);
	if (n % 2 == 0)
		return (ans * ans) % 233333;
	else
		return ((ans * ans) % 233333 * x) % 233333;
}
int main()
{
	int x, n;
	cin >> x >> n;
	cout << power(x, n);
}