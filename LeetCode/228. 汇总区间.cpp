class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        nums.emplace_back(INT_MIN + 1);
        int start = nums[0], end = nums[0], n = nums.size();
        vector<string> res;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - 1 == end)
                ++end;
            else {
                if (start < end)
                    res.emplace_back(to_string(start) + "->" + to_string(end));
                else
                    res.emplace_back(to_string(start));
                start = end = nums[i];
            }
        }
        return res;
    }
};
