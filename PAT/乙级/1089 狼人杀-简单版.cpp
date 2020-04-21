#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool inline islie(vector<int>& nums, int i, int j, int k)
{
	return (nums[k] > 0 && (nums[k] == i + 1 || nums[k] == j + 1))
		|| (nums[k] < 0 && (-nums[k] != i + 1 && -nums[k] != j + 1));
}
int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			if (islie(nums, i, j, i) == islie(nums, i, j, j))
				continue;
			int count = 0;
			for (int k = 0; k < n && count < 2; ++k)
			{
				if (k == i || k == j)
					continue;
				if (islie(nums, i, j, k))
					++count;
			}
			if (count == 1)
			{
				cout << i + 1 << ' ' << j + 1;
				return 0;
			}
		}
	cout << "No Solution";
	return 0;
}