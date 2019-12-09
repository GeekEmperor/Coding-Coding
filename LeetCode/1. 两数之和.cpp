class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i) {
			if (m.count(target - nums[i]))
				return { m[target - nums[i]], i };
			m[nums[i]] = i;
		}
		return { 0, 0 };
	}
};