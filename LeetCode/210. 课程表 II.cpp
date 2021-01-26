class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        vector<int> order;
        int n = prerequisites.size(), i, j, k = 0;
        for (int i = 0; i < n; ++i) {
            graph[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
            ++degree[prerequisites[i][0]];
        }
        for (int i = 0; i < numCourses; ++i)
            if (degree[i] == 0)
                order.emplace_back(i);
        while (k < order.size()) {
            i = order[k++];
            for (j = 0; j < graph[i].size(); ++j)
                if (--degree[graph[i][j]] == 0)
                    order.emplace_back(graph[i][j]);
        }
        if (k < numCourses)
            return {};
        else
            return order;
    }
};