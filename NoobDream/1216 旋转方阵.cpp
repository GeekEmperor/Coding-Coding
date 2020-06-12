#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[20][20];
	int x = 0, y = 0, t = 0, b = n - 1, l = 0, r = n - 1, m = 1;
	while (true)
	{
		while (x < b)
			a[x++][y] = m++;
		if (++l > r)
			break;
		while (y < r)
			a[x][y++] = m++;
		if (--b < t)
			break;
		while (x > t)
			a[x--][y] = m++;
		if (--r < l)
			break;
		while (y > l)
			a[x][y--] = m++;
		if (++t > b)
			break;
	}
	a[x][y] = n * n;
	for (x = 0; x < n; ++x)
	{
		for (y = 0; y < n; ++y)
			printf("%-3d ", a[x][y]);
		putchar('\n');
	}
}