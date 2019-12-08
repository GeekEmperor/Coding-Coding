#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> arr(10);
	for (int i = 0; i < 10; ++i)
		cin >> arr[i];
	for (int i = 1; i < 10; ++i)
		if (arr[i])
		{
			cout << i;
			--arr[i];
			break;
		}
	for (int i = 0; i < 10; ++i)
		while (arr[i]--)
			cout << i;
	return 0;
}