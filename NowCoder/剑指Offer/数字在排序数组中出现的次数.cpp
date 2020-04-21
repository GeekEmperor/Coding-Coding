class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int l = 0, r = data.size() - 1, m, i, j;
        while (l <= r) {
            m = (l + r) >> 1;
            if (data[m] < k)
                l = m + 1;
            else
                r = m - 1;
        }
        i = l;
        l = 0, r = data.size() - 1;
        while (l <= r) {
            m = (l + r) >> 1;
            if (data[m] <= k)
                l = m + 1;
            else
                r = m - 1;
        }
        j = r;
        return j - i + 1;
    }
};