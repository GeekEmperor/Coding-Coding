#include <iostream>
using namespace std;
int main()
{
	int n, cur = 0, num, time = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		if (num > cur)
			time += 6 * (num - cur) + 5;
		else if (num < cur)
			time += 4 * (cur - num) + 5;
		else
			time += 5;
		cur = num;
	}
	cout << time;
	return 0;
}