#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	m %= n;
	reverse(arr, arr + n);
	reverse(arr, arr + m);
	reverse(arr + m, arr + n);
	cout << arr[0];
	for (int i = 1; i < n; ++i)
		cout << ' ' << arr[i];
	delete[] arr;
	return 0;
}