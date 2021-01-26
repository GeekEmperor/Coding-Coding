class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end())
            return -1;
        int value = it->second->second;
        l.erase(it->second);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end())
            l.erase(it->second);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if (l.size() > cap) {
            m.erase(l.back().first);
            l.pop_back();
        }
    }
};
