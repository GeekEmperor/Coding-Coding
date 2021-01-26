class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<list<int>> graph(n);
        vector<int> degree(n, 0);
        for (const auto& e : edges)
        {
            int u = e[0], v = e[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
            ++degree[u];
            ++degree[v];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (degree[i] <= 1)
                q.push(i);
        vector<int> root;
        while (!q.empty())
        {
            root.clear();
            int size = q.size();
            while (size--)
            {
                int u = q.front();
                q.pop();
                root.emplace_back(u);
                for (int v : graph[u])
                    if (--degree[v] == 1)
                        q.push(v);
            }
        }
        return root;
    }
};