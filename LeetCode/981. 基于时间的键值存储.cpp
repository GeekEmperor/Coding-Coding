class TimeMap {
private:
    unordered_map<string, vector<int>> a;
    unordered_map<string, vector<string>> b;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        a[key].emplace_back(timestamp);
        b[key].emplace_back(value);
    }
    
    string get(string key, int timestamp) {
        auto& arr = a[key];
        int l = 0, r = arr.size() - 1, m = 0;
        while (l <= r) {
            m = (l + r) >> 1;
            if (arr[m] <= timestamp)
                l = m + 1;
            else
                r = m - 1;
        }
        return r < arr.size() ? b[key][r] : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
