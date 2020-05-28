#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
	string s;
	cin >> s;
	while (s != "END")
	{
		int raw = s.size() * 8;
		int freqs[128] = { 0 };
		for (char c : s)
			++freqs[c];
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < 128; ++i)
			if (freqs[i])
				pq.push(freqs[i]);
		int compress = 0;
		if (pq.size() == 1)
			compress = s.size();
		while (pq.size() > 1)
		{
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			compress += a + b;
			pq.push(a + b);
		}
		printf("%d %d %.1f\n", raw, compress, (float)raw / compress);
		cin >> s;
	}
}