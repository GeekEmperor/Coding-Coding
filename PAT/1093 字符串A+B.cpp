#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b, c;
	getline(cin, a);
	getline(cin, b);
	bool exist[128] = { 0 };
	for (int i = 0; i < a.size(); ++i)
		if (!exist[a[i]])
		{
			c += a[i];
			exist[a[i]] = true;
		}
	for (int i = 0; i < b.size(); ++i)
		if (!exist[b[i]])
		{
			c += b[i];
			exist[b[i]] = true;
		}
	cout << c;
	system("pause");
	return 0;
}