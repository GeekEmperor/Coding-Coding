class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int j = i + 1, k = n - 1;
                while (j < k) {
                    int s = nums[j] + nums[i] + nums[k];
                    if (s == 0) {
                        res.push_back({ nums[i], nums[j++], nums[k--] });
                        while (j < k && nums[j] == nums[j - 1])
                            ++j;
                        while (j < k && nums[k] == nums[k + 1])
                            --k;
                    }
                    else if (s < 0)
                        ++j;
                    else
                        --k;
                }
            }
        }
        return res;
    }
};