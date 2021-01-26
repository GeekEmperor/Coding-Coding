class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> a;
        unordered_set<string> b;
        int n = s.size();
        for (int i = 0; i <= n - 10; ++i) {
            string t(s.substr(i, 10));
            if (a.count(t))
                b.insert(t);
            else
                a.insert(t);
        }
        return vector<string>(b.begin(), b.end());
    }
};
