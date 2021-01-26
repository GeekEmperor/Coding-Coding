class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        int count = 0;
        for (auto v : prerequisites) {
            graph[v[0]].push_back(v[1]);
            degree[v[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (!degree[i])
                q.push(i);
        while (!q.empty()) {
            count++;
            int u = q.front();
            q.pop();
            for (auto v : graph[u])
                if (--degree[v] <= 0)
                    q.push(v);
        }
        return count == numCourses;
    }
};