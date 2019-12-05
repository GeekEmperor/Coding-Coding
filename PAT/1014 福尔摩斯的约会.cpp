#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	const char* day[] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	char arr[4][61];
	for (int i = 0; i < 4; ++i)
		cin >> arr[i];
	int i = 0;
	for (i = 0; arr[0][i] && arr[1][i]; ++i)
		if (arr[0][i] == arr[1][i] && arr[0][i] >= 'A' && arr[0][i] <= 'G')
			break;
	cout << day[arr[0][i] - 'A'] << ' ';
	for (i = i + 1; arr[0][i] && arr[1][i]; ++i)
		if (arr[0][i] == arr[1][i] && (isdigit(arr[0][i]) || (arr[0][i] >= 'A' && arr[0][i] <= 'N')))
			break;
	if (isdigit(arr[0][i]))
		cout << '0' << arr[0][i] << ':';
	else
		cout << (arr[0][i] - 'A' + 10) << ':';
	for (i = 0; arr[2][i] && arr[3][i]; ++i)
		if (arr[2][i] == arr[3][i] && isalpha(arr[2][i]))
			break;
	if (i < 10)
		cout << 0 << i;
	else
		cout << i;
	return 0;
}