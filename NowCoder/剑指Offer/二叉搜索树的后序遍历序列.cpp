class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;
        return sequence.empty() ? false :Verify(sequence, 0, sequence.size() - 1);
    }
    bool Verify(vector<int>& sequence, int s, int e) {
        if (s >= e)
            return true;
        int i, j;
        for (i = s; i < e; ++i)
            if (sequence[i] > sequence[e])
                break;
        for (j = i; j < e; ++j)
            if (sequence[j] < sequence[e])
                return false;
        return Verify(sequence, s, i - 1) && Verify(sequence, i, e - 1);
    }
};