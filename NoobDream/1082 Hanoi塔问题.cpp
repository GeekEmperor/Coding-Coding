#include <iostream>
using namespace std;
int count;
void move(char a, char b, char c, int n)
{
	if (!n)
		return;
	move(a, c, b, n - 1);
	cout << a << "-->" << c << "   ";
	if (++count == 5)
	{
		cout << endl;
		count = 0;
	}
	move(b, a, c, n - 1);
}
int main()
{
	int n;
	while (cin >> n && n)
	{
		count = 0;
		move('A', 'B', 'C', n);
		cout << endl;
	}
}