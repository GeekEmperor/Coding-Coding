class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int neighs[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        dis[0][0] = 0;
        priority_queue<pair<int, int>> pq;
        if (n > 1)
            pq.push({-abs(heights[0][1]-heights[0][0]), 1});
        if (m > 1)
            pq.push({-abs(heights[1][0]-heights[0][0]), 1 << 8});
        while (!pq.empty()) {
            auto edge = pq.top();
            int w = -edge.first, st = edge.second;
            pq.pop();
            int si = (st >> 24) & 0xff, sj = (st >> 16) & 0xff, ti = (st >> 8) & 0xff, tj = st & 0xff;
            dis[ti][tj] = max(w, dis[si][sj]);
            if (ti == m-1 && tj == n-1)
                break;
            for (int k = 0; k < 4; ++k) {
                int vi = ti + neighs[k][0], vj = tj + neighs[k][1];
                if (vi >= 0 && vi < m && vj >= 0 && vj < n && dis[vi][vj] == INT_MAX)
                    pq.push({-abs(heights[vi][vj]-heights[ti][tj]), (ti << 24) | (tj << 16) | (vi << 8) | vj});
            }
        }
        return dis[m-1][n-1];
    }
};