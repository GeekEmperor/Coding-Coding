class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        int temp[26];
        // 构建temp数组
        for (int i = 0; i < 26; ++i)
            temp[order[i] - 'a'] = i;
        for (int i = 0; i < n; ++i) {
            // 进行变换
            for (int j = 0; j < words[i].size(); ++j)
                words[i][j] = temp[words[i][j] - 'a'] + 'a';
            // 前向比较
            if (i > 0 && words[i] < words[i - 1])
                return false;
        }
        return true;
    }
};