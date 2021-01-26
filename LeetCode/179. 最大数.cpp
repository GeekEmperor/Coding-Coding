class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size(), i;
        vector<string> temp(n);
        for (i = 0; i < n; ++i)
            temp[i] = to_string(nums[i]);
        sort(temp.begin(), temp.end(), [](const string &a, const string &b){return a + b < b + a;});
        string res;
        for (i = n - 1; i >= 0; --i)
            res += temp[i];
        return (res[0] == '0') ? "0" : res;
    }
};
