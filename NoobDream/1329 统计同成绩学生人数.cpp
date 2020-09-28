#include <iostream>
using namespace std;
int main()
{
	int n, x, y;
	cin >> n;
	while (n)
	{
		int a[101] = {0};
		while (n--)
		{
			cin >> x;
			++a[x];
		}
		cin >> y;
		cout << a[y] << endl;
		cin >> n;
	}
}