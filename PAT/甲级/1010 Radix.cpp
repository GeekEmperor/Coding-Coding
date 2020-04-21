#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long stol(string s, int radix)
{
	long long ans = 0;
	for (char c : s)
		if (c <= '9')
			ans = radix * ans + c - '0';
		else
			ans = radix * ans + c - 'a' + 10;
	return ans;
}
long long find(string s, long long n)
{
	char c = *max_element(s.begin(), s.end());
	long long low = (c <= '9' ? c - '0' : c - 'a' + 10) + 1, high = n + 1, mid;
	while (low <= high)
	{
		mid = (low + high) >> 1;
		long long temp = stol(s, mid);
		if (temp == n)
			return mid;
		else if (temp < 0 || temp > n)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int main()
{
	string n1, n2;
	int tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2)
		swap(n1, n2);
	long long n = stol(n1, radix);
	long long ans = find(n2, n);
	if (ans == -1)
		cout << "Impossible";
	else
		cout << ans;
	return 0;
}