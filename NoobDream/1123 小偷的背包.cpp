#include <iostream>
#include <vector>
using namespace std;
bool backtrack(vector<int>& w, vector<bool>& v, int s)
{
	if (!s)
		return true;
	for (int i = 0; i < w.size(); ++i)
		if (!v[i] && w[i] <= s)
		{
			v[i] = true;
			if (backtrack(w, v, s - w[i]))
				return true;
			else
				v[i] = false;
		}
	return false;
}
int main()
{
	int s, n;
	cin >> s >> n;
	vector<int> w(n);
	for (int i = 0; i < n; ++i)
		cin >> w[i];
	vector<bool> v(n, false);
	if (backtrack(w, v, s))
		cout << "yes!";
	else
		cout << "no!";
}