class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty())
            return {};
        vector<int> map(k, 0);
        vector<pair<int, int>> heap(nums1.size());
        vector<vector<int>> ans;
        for (int i = 0; i < nums1.size(); ++i)
            heap[i] = make_pair(-nums1[i]-nums2[0], i);
        make_heap(heap.begin(), heap.end());
        for (int i = 0; i < k && !heap.empty(); ++i) {
            pop_heap(heap.begin(), heap.end());
            int j = heap.back().second;
            ans.push_back({nums1[j], nums2[map[j]]});
            if (++map[j] < nums2.size()) {
                heap.back().first = -nums1[j]-nums2[map[j]];
                push_heap(heap.begin(), heap.end());
            }
            else
                heap.pop_back();
        }
        return ans;
    }
};