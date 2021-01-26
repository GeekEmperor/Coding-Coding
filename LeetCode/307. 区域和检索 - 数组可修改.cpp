class NumArray {
private:
    vector<int> data;
public:
    NumArray(vector<int>& nums) : data(nums) {
        
    }
    
    void update(int i, int val) {
        data[i] = val;
    }
    
    int sumRange(int i, int j) {
        int res = 0;
        while (i <= j)
            res += data[i++];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */