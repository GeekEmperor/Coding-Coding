#include <iostream>
#include <vector>
using namespace std;
bool check(vector<int>& v, int i)
{
	if (i >= v.size())
		return true;
	int j = (i << 1) + 1;
	if (j < v.size() && v[i] > v[j])
		return false;
	if (j + 1 < v.size() && v[i] > v[j + 1])
		return false;
	return check(v, j) && check(v, j + 1);
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	if (check(v, 0))
		cout << "Yes";
	else
		cout << "No";
}