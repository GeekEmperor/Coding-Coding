#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), l = 0;
        vector<vector<int>> g(n);
        vector<bool> v(n, false);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (i < n - 1)
                g[i].emplace_back(i+1);
            for (int j = n - 1; j > i; --j)
                if (arr[i] == arr[j]) {
                    g[i].emplace_back(j);
                    g[j].emplace_back(i);
                }
            if (i > 0)
                g[i].emplace_back(i-1);
        }
        v[0] = true;
        q.push(0);
        while (!q.empty()) {
            ++l;
            int s = q.size();
            while (s--) {
                int i = q.front();
                q.pop();
                for (int j : g[i]) {
                    if (j == n - 1)
                        return l;
                    if (!v[j]) {
                        v[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        return 0;
    }
};