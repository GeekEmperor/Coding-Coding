class NestedIterator {
private:
    vector<int> data;
    int index;
    
    void dfs(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for (int i = 0; i < n; ++i) {
            if (nestedList[i].isInteger())
                data.emplace_back(nestedList[i].getInteger());
            else
                dfs(nestedList[i].getList());
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        index = 0;
    }

    int next() {
        return data[index++];
    }

    bool hasNext() {
        return index < data.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
