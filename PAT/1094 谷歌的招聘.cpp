#include <iostream>
#include <string>
using namespace std;
bool isprime(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;
}
int main()
{
	int l, k;
	string s;
	cin >> l >> k >> s;
	for (int i = 0; i <= l - k; ++i)
		if (isprime(stoi(s.substr(i, k))))
		{
			cout << s.substr(i, k) << endl;
			return 0;
		}
	cout << "404\n";
	return 0;
}