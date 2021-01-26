class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.empty())
            return true;
        int n = graph.size();
        vector<bool> visit(n, false);
        vector<bool> color(n, false);
        for (int i = 0; i < n; ++i)
            if (!visit[i]) {
                queue<int> q;
                visit[i] = color[i] = true;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int j = 0; j < graph[u].size(); ++j) {
                        int v = graph[u][j];
                        if (!visit[v]) {
                            visit[v] = true;
                            color[v] = !color[u];
                            q.push(v);
                        }
                        else if (color[v] == color[u])
                            return false;
                    }
            }
        }
        return true;
    }
};