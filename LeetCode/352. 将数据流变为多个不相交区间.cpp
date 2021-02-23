class SummaryRanges {
private:
    set<int> s;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }
    
    void addNum(int val) {
        s.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int l = *s.begin(), r = *s.begin();
        for (int n : s) {
            if (n > r + 1) {
                ans.push_back({l, r});
                l = n;
            }
            r = n;
        }
        ans.push_back({l, r});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */