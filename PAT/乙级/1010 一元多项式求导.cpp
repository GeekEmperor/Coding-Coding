#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> res;
	int c, e;
	while (cin >> c >> e)
		if (c * e)
		{
			res.emplace_back(c * e);
			res.emplace_back(e - 1);
		}
	if (res.empty())
		cout << "0 0";
	else
	{
		cout << res[0];
		for (int i = 1; i < res.size(); ++i)
			cout << ' ' << res[i];
	}
	return 0;
}