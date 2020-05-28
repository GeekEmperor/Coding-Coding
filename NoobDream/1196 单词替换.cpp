#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string s, a, b;
	getline(cin, s);
	while (cin >> a >> b)
	{
		vector<string> v;
		int i = 0, j = s.find(' ');
		while (j != -1)
		{
			v.push_back(s.substr(i, j - i));
			i = j + 1;
			j = s.find(' ', j + 1);
		}
		v.push_back(s.substr(i));
		for (i = 0; i < v.size(); ++i)
		{
			if (v[i] == a)
				v[i] = b;
			cout << v[i] << ' ';
		}
		cout << endl;
		getline(cin, s);
	}
}