class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        int from = 0, to = stoi(target), level = 0;
        if (from == to)
            return level;
        vector<int> step = { 1000, 100, 10, 1 };
        vector<bool> visit(10000, false);
        for (string s : deadends)
            visit[stoi(s)] = true;
        if (visit[from])
            return -1;
        visit[from] = true;
        queue<int> q;
        q.push(from);
        while (!q.empty()) {
            ++level;
            int size = q.size();
            while (size--) {
                int current = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int add = current + step[i];
                    if (current / step[i] % 10 == 9)
                        add = current - 9 * step[i];
                    if (add == to)
                        return level;
                    else if (!visit[add])
                        visit[add] = true, q.push(add);
                    int sub = current - step[i];
                    if (current / step[i] % 10 == 0)
                        sub = current + 9 * step[i];
                    if (sub == to)
                        return level;
                    else if (!visit[sub])
                        visit[sub] = true, q.push(sub);
                }
            }
        }
        return -1;
    }
};