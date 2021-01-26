class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> temp;
        nums.emplace_back(INT_MAX);
        int i = 0, j, n = nums.size();
        for (j = 0; j < n; ++j) {
            if (nums[j] != nums[i]) {
                temp.emplace_back(make_pair(nums[i], j - i));
                i = j;
            }
        }
        sort(temp.begin(), temp.end(), [](auto& x, auto& y) {return x.second > y.second; });
        vector<int> res(k);
        for (i = 0; i < k; ++i)
            res[i] = temp[i].first;
        return res;
    }
};