class Solution {
public:
    int InversePairs(vector<int> data) {
        if (data.empty())
            return 0;
        vector<int> temp(data);
        return MergeSort(data, temp, 0, data.size());
    }
     
    int MergeSort(vector<int>& data, vector<int>& temp, int b, int e) {
        if (b + 1 >= e)
            return 0;
        int m = (b + e) >> 1;
        int count = (MergeSort(data, temp, b, m) + MergeSort(data, temp, m, e)) % 1000000007;
        int i = b, j = m, k = b;
        while (i < m && j < e) {
            if (data[i] <= data[j])
                temp[k++] = data[i++];
            else {
                temp[k++] = data[j++];
                count += m - i;
                if (count > 1000000007)
                    count %= 1000000007;
            }
        }
        while (i < m)
            temp[k++] = data[i++];
        while (j < e)
            temp[k++] = data[j++];
        for (int k = b; k < e; ++k)
            data[k] = temp[k];
        return count % 1000000007;
    }
};