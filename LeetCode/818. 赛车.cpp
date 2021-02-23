#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int racecar(int target) {
        if (!target)
            return 0;
        int step = 0, pos, speed;
        vector<bool> visit(target+1);
        queue<pair<int, int>> q;
        visit[0] = true;
        q.push(make_pair(0, 1));
        while (!q.empty()) {
            ++step;
            int size = q.size();
            while (size--) {
                auto p = q.front();
                q.pop();
                pos = p.first, speed = p.second;
                if ((pos += speed) == target)
                    return step;
                if (!visit[pos]) {
                    visit[pos] = true;
                    q.push(make_pair(pos, speed*2));
                }
                pos = p.first;
                if (speed > 0)
                    q.push(make_pair(pos, -1));
                else
                    q.push(make_pair(pos, 1));
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    cout << sol.racecar(3) << endl;
}