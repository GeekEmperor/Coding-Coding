class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visit;
    void dfs(int u) {
        for (int v : graph[u])
            if (!visit[v]) {
                visit[v] = true;
                dfs(v);
            }
    }
    int numSimilarGroups(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size(), count = 0;
        graph.resize(m);
        visit.resize(m);
        for (int i = 0; i < m; ++i)
            for (int j = i + 1; j < m; ++j) {
                int k = 0, diff = 0;
                for (; diff <= 2 && k < n; ++k)
                    if (strs[i][k] != strs[j][k])
                        ++diff;
                if (diff <= 2 && k >= n) {
                    graph[i].emplace_back(j);
                    graph[j].emplace_back(i);
                }
            }
        for (int i = 0; i < m; ++i)
            if (!visit[i]) {
                dfs(i);
                ++count;
            }
        return count;
    }
};