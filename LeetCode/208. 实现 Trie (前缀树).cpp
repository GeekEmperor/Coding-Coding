class Node {
public:
    bool end;
    Node* child[26];
    Node() : end(false), child{0} {}
};
class Trie {
public:
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = root;
        for (char c : word) {
            Node*& q = p->child[c - 'a'];
            if (!q)
                q = new Node;
            p = q;
        }
        p->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = root;
        for (char c : word) {
            Node* q = p->child[c - 'a'];
            if (!q)
                return false;
            p = q;
        }
        return p->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* p = root;
        for (char c : prefix) {
            Node* q = p->child[c - 'a'];
            if (!q)
                return false;
            p = q;
        }
        return true;
    }
};