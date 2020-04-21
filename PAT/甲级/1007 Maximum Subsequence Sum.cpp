#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int main()
{
	int k;
	cin >> k;
	vector<int> data(k);
	for (int i = 0; i < k; ++i)
		cin >> data[i];
	int mss = INT_MIN, sum = 0, begin = 0, end = k - 1;
	for (int i = 0; i < k; ++i)
	{
		sum += data[i];
		if (sum < 0)
			sum = 0;
		else if (sum > mss)
			mss = sum;
	}
	sum = 0;
	if (mss < 0)
		mss = 0;
	else
		for (int i = 0; i < k; ++i)
		{
			sum += data[i];
			if (sum < 0)
			{
				begin = i + 1;
				sum = 0;
			}
			else if (sum == mss)
			{
				end = i;
				break;
			}
		}
	cout << mss << ' ' << data[begin] << ' ' << data[end];
	return 0;
}