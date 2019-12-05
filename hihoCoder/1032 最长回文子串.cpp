#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	while (n--)
	{
		cin >> s;
		string t(2 * s.size() + 3, '\0');
		t[0] = '$', t[1] = '#';
		for (int i = 0; i < s.size(); ++i)
			t[(i << 1) + 2] = s[i], t[(i << 1) + 3] = '#';
		vector<int> arr(t.size(), 1);
		int index = 1, len = 1;
		for (int i = 1; i < t.size(); ++i)
		{
			if (i < index + arr[index])
				arr[i] = min(arr[2 * index - i], index + arr[index] - i);
			while (t[i - arr[i]] == t[i + arr[i]])
				++arr[i];
			if (i + arr[i] > index + arr[index])
				index = i;
			if (arr[i] - 1 > len)
				len = arr[i] - 1;
		}
		cout << len << endl;
	}
	return 0;
}
