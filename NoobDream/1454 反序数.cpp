#include <iostream>
using namespace std;
int main()
{
	for (int i = 1000; i < 10000; ++i)
	{
		int n = i, j = 0;
		while (n)
		{
			j *= 10;
			j += n % 10;
			n /= 10;
		}
		if (9 * i == j)
			cout << i << ' ';
	}
}