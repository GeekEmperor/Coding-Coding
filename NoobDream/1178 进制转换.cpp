#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char s[31];
	int num[31];
	int res[100];
	while (scanf("%s", s) != EOF)
	{
		int n = strlen(s);
		for (int i = 0; i < n; ++i)
			num[i] = s[i] - '0';
		int head = 0, tail = 0;
		while (head < n)
		{
			res[tail++] = num[n - 1] & 1;
			int c = 0, t;
			for (int i = head; i < n; ++i)
			{
				t = num[i];
				num[i] = (num[i] + c) / 2;
				if (t & 1)
					c = 10;
				else
					c = 0;
			}
			if (num[head] == 0)
				++head;
		}
		for (int i = tail - 1; i >= 0; --i)
			printf("%d", res[i]);
		putchar('\n');
	}
}