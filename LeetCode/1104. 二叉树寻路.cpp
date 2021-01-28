class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int bits = 0, temp = label;
        while (temp) {
            temp >>= 1;
            ++bits;
        }
        vector<int> path(bits--, 0);
        path[bits] = label;
        while (bits) {
            --bits;
            label = (1 << bits) + (2 << bits) - 1 - (label >> 1);
            path[bits] = label;
        }
        return path;
    }
};