class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        DFS(res, nums, temp, 0);
        return res;
    }
    void DFS(vector<vector<int>>& res, vector<int>& nums, vector<int>& temp, int i) {
        res.push_back(temp);
        for (int j = i; j < nums.size(); ++j)
        {
            if (j > i&& nums[j] == nums[j - 1])
                continue;
            temp.push_back(nums[j]);
            DFS(res, nums, temp, j + 1);
            temp.pop_back();
        }
    }
};