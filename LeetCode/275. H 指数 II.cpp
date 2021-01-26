class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), i = 0;
        while (i < n && i + citations[i] < n)
            ++i;
        return n - i;
    }
};