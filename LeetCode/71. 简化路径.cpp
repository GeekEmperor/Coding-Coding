class Solution {
public:
    string simplifyPath(string path) {
        int i = 0, j = 0, n = path.length();
        string temp, res;
        vector<string> s;
        while (i < n) {
            for (j = i; j < n; ++j)
                if (path[j] == '/')
                    break;
            temp = path.substr(i, j - i);
            i = j + 1;
            if (temp == ".") continue;
            if (temp == ".." && !s.empty()) s.pop_back();
            if (temp != ".." && !temp.empty()) s.push_back(temp);
        }
        for (int i = 0; i < s.size(); ++i)
            res += "/" + s[i];
        return res.empty() ? "/" : res;
    }
};