class WordDictionary {
private:
    struct Node {
        bool isword = 0;
        Node* child[26] = {0};
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.size();
        Node* p = root;
        for (int i = 0; i < n; ++i) {
            if (!p->child[word[i] - 'a'])
                p->child[word[i] - 'a'] = new Node;
            p = p->child[word[i] - 'a'];
        }
        p->isword = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, root);
    }
    bool dfs(string& word, int k, Node* p) {
        int n = word.size();
        if (k >= n)
            return p->isword;
        if (word[k] == '.') {
            for (int i = 0; i < 26; ++i)
                if (p->child[i] && dfs(word, k + 1, p->child[i]))
                    return true;
            return false;
        }
        else
            return p->child[word[k] - 'a'] && dfs(word, k + 1, p->child[word[k] - 'a']);
        return false;
    }
};
