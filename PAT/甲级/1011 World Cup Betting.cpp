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
	char s[3] = { 'W','T','L' };
	float odds[3], profit = 1;
	for (int i = 0; i < 3; ++i)
	{
		cin >> odds[0] >> odds[1] >> odds[2];
		int idx = 0;
		if (odds[1] > odds[idx])
			idx = 1;
		if (odds[2] > odds[idx])
			idx = 2;
		profit *= odds[idx];
		cout << s[idx] << ' ';
	}
	profit = (profit * 0.65 - 1) * 2;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << profit;
	return 0;
}