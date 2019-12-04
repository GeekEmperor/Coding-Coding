#include <iostream>
#include <string>
using namespace std;
int main()
{
	const char* arr[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	string s;
	cin >> s;
	int sum = 0;
	for (char c : s)
		sum += c - '0';
	string t = to_string(sum);
	int m = t.size();
	for (int i = 0; i < m - 1; ++i)
		cout << arr[t[i] - '0'] << ' ';
	cout << arr[t[m - 1] - '0'];
	return 0;
}