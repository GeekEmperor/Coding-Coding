#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char str[81];
	cin.getline(str, 81);
	int n = strlen(str);
	reverse(str, str + n);
	for (int i = 0, j = 0; j <= n; ++j)
		if (str[j] == ' ' || !str[j])
		{
			reverse(str + i, str + j);
			i = j + 1;
		}
	cout << str;
	return 0;
}