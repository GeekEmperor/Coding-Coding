#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string n;
	cin >> n;
	vector<int> arr(10, 0);
	for (int i = 0; i < n.size(); ++i)
		++arr[n[i] - '0'];
	for (int i = 0; i < 10; ++i)
		if (arr[i])
			cout << i << ':' << arr[i] << endl;
	return 0;
}