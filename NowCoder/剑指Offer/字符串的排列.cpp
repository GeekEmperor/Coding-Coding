class Solution {
public:
    /*
    vector<string> Permutation(string str) {
        if (str.empty())
            return {};
        set<string> s;
        permutation(str, s, 0);
        return vector<string>(s.begin(), s.end());
    }
    void permutation(string& str, set<string>& s, int i) {
        if (i >= str.size()) {
            s.insert(str);
            return;
        }
        for (int j = i; j < str.size(); ++j) {
            swap(str[i], str[j]);
            permutation(str, s, i + 1);
            swap(str[i], str[j]);
        }
    }
    */
    vector<string> Permutation(string str) {
        if (str.empty())
            return {};
        sort(str.begin(), str.end());
        vector<string> res;
        Permutation(str, res, 0);
        sort(res.begin(), res.end());
        return res;
    }
    void Permutation(string& str, vector<string>& res, int i) {
        if (i >= str.size()) {
            res.emplace_back(str);
            return;
        }
        for (int j = i; j < str.size(); ++j) {
            if (i == j || str[i] != str[j]) {
                swap(str[i], str[j]);
                Permutation(str, res, i + 1);
                swap(str[i], str[j]);
            }
        }
    }
};