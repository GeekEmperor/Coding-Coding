class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) 
            return 0;
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                string word(q.front()); 
                q.pop();
                for (int i = 0; i < word.size(); ++i) {
                    string newWord(word);
                    for (char c = 'a'; c <= 'z'; ++c) {
                        newWord[i] = c;
                        if (newWord == endWord)
                            return level + 1;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }   
                    }
                }
            }
            ++level;
        }
        return 0;
    }
};