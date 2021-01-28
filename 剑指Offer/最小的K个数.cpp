class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int n = input.size();
        if (!n || !k || k > n)
            return {};
        priority_queue<int> heap(k, INT_MAX);
        for (int i = 0; i < n; ++i)
            if (heap.top() > input[i]) {
                heap.pop();
                heap.push(input[i]);
            }
        vector<int> res;
        while (!heap.empty()) {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};