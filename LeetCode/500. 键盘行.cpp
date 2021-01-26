class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<set<char>> d = {
            {'q','w','e','r','t','y','u','i','o','p'},
            {'a','s','d','f','g','h','j','k','l'},
            {'z','x','c','v','b','n','m'},
        };
        int i, j, k;
        vector<string> res;
        for (i = 0; i < words.size(); ++i) {
            for (k = 0; k < 3; ++k)
                if (d[k].count(words[i][0]|32))
                    break;
            for (j = 1; j < words[i].size(); ++j)
                if (!d[k].count(words[i][j]|32))
                    break;
            if (j >= words[i].size())
                res.emplace_back(words[i]);
        }
        return res;
    }
};