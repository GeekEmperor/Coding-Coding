class Solution {
private:
    map<int, vector<int>> m = {{1, {1}}};
public:
    vector<int> beautifulArray(int N) {
        if (m.count(N))
            return m[N];
        vector<int> left = beautifulArray((N+1)/2);
        vector<int> right = beautifulArray(N/2);
        vector<int> arr(N);
        int i = 0, j = 0;
        for (i = 0; i < (N+1)/2; ++i, ++j)
            arr[j] = (left[i]<<1)-1;
        for (i = 0; i < N/2; ++i, ++j)
            arr[j] = right[i]<<1;
        m[N] = arr;
        return arr;
    }
};