#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n, a, b;
	scanf("%d", &n);
	do
	{
		while (n < 1000)
			n *= 10;
		string s = to_string(n);
		sort(s.begin(), s.end());
		b = stoi(s);
		reverse(s.begin(), s.end());
		a = stoi(s);
		n = a - b;
		printf("%04d - %04d = %04d\n", a, b, n);
	} while (n != 6174 && n != 0);
	return 0;
}