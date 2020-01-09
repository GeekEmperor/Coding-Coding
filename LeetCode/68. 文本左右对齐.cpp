class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0, j = 0, k = 0, width = 0, interval = 0;
        vector<string> res;
        for (; i < words.size(); ++i) {
            if (width + words[i].size() + i - j - 1 >= maxWidth) {
                string temp = words[j++];
                if (j < i) {
                    interval = (maxWidth - width) / (i - j);
                    k = j + (maxWidth - width) % (i - j);
                    for (; j < k; ++j)
                        temp += string(interval + 1, ' ') + words[j];
                    for (; j < i; ++j)
                        temp += string(interval, ' ') + words[j];
                }
                else if (temp.size() < maxWidth)
                    temp += string(maxWidth - temp.size(), ' ');
                res.emplace_back(temp);
                width = 0;
            }
            width += words[i].size();
        }
        string temp;
        for (; j < i - 1; ++j)
            temp += words[j] + ' ';
        temp += words[j];
        if (temp.size() < maxWidth)
            temp += string(maxWidth - temp.size(), ' ');
        res.emplace_back(temp);
        return res;
    }
};