#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m, x;
	cin >> n >> m;
	vector<int> sales(n, 0);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> x;
			sales[j] += x;
		}
	int idx = 0;
	for (int i = 0; i < n; ++i)
		if (sales[i] > sales[idx])
			idx = i;
	cout << sales[idx] << endl;
	cout << idx;
	for (int i = 0; i < n; ++i)
		if (sales[i] == sales[idx] && i != idx)
			cout << ' ' << idx;
	system("pause");
	return 0;
}