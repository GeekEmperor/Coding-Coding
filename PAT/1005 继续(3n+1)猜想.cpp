#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int k;
	cin >> k;
	int* arr = new int[k];
	bool visit[101] = { false };
	for (int i = 0; i < k; ++i)
		cin >> arr[i];
	for (int i = 0; i < k; ++i)
		if (!visit[arr[i]])
		{
			int n = arr[i];
			while (n != 1)
			{
				if (n & 1)
					n = (3 * n + 1) >> 1;
				else
					n >>= 1;
				if (n <= 100)
					visit[n] = true;
			}
		}
	int* res = new int[k];
	int m = 0;
	for (int i = 0; i < k; ++i)
		if (!visit[arr[i]])
			res[m++] = arr[i];
	sort(res, res + m);
	for (int i = m - 1; i > 0; --i)
		cout << res[i] << ' ';
	cout << res[0];
	delete[] arr;
	delete[] res;
	return 0;
}