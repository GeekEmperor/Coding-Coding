class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); ++i) {
            string str(strs[i]);
            sort(str.begin(), str.end());
            m[str].emplace_back(strs[i]);
        }
        for (const auto& it : m) {
            res.emplace_back(it.second);
        }
        return res;
    }
};