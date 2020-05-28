#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, k, q, c;
    cin >> n >> m >> k >> q;
    vector<int> t(k);
    for (int i = 0; i < k; ++i)
        cin >> t[i];
    vector<int> ans(t);
    vector<queue<int>> windows(n);
    for (int i = 0; i < min(k, n * m); ++i)
    {
        int j = i % n;
        if (i >= n)
            ans[i] = ans[windows[j].back()] + t[i];
        windows[j].push(i);
    }
    for (int i = min(k, n * m); i < k; ++i)
    {
        int j = 0;
        for (int i = 0; i < n; ++i)
            if (ans[windows[i].front()] < ans[windows[j].front()])
                j = i;
        ans[i] = ans[windows[j].back()] + t[i];
        windows[j].pop();
        windows[j].push(i);
    }
    while (q--)
    {
        cin >> c;
        --c;
        if (ans[c] - t[c] >= 540)
            cout << "Sorry\n";
        else
            cout << setw(2) << setfill('0') << (ans[c] / 60 + 8) << ':' << setw(2) << setfill('0') << (ans[c] % 60) << '\n';
    }
    system("pause");
}