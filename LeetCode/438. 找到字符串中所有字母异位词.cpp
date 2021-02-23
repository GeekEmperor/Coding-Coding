
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if (m < n)
            return {};
        vector<int> a(26, 0), b(26, 0);
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ++a[s[i]-'a'];
            ++b[p[i]-'a'];
        }
        for (int i = n; i < m; ++i) {
            if (a == b)
                ans.emplace_back(i-n);
            ++a[s[i]-'a'];
            --a[s[i-n]-'a'];
        }
        if (a == b)
            ans.emplace_back(m-n);
        return ans;
    }
};