#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct mooncake
{
	float inventory, total, unit;
	bool operator<(mooncake& m) { return unit > m.unit; }
};
int main()
{
	int n, d;
	cin >> n >> d;
	vector<mooncake> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i].inventory;
	for (int i = 0; i < n; ++i)
		cin >> arr[i].total;
	for (int i = 0; i < n; ++i)
		arr[i].unit = arr[i].total / arr[i].inventory;
	sort(arr.begin(), arr.end());
	float earning = 0.0;
	for (int i = 0; i < n && d; ++i)
		if (d >= arr[i].inventory)
		{
			earning += arr[i].total;
			d -= arr[i].inventory;
		}
		else
		{
			earning += d * arr[i].unit;
			d = 0;
		}
	cout.setf(cout.fixed);
	cout.precision(2);
	cout << earning;
	return 0;
}