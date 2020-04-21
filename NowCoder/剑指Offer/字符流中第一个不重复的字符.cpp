class Solution
{
private:
    int index[128];
    int count;
public:
    Solution()
    {
        for (int i = 0; i < 128; ++i)
            index[i] = INT_MAX;
        count = 0;
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if (index[ch] == INT_MAX)
            index[ch] = count;
        else
            index[ch] = INT_MIN;
        count++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char res = '\0';
        for (int i = 0; i < 128; ++i)
            if (index[i] != INT_MIN && index[i] < index[res])
                res = i;
        return index[res] == INT_MAX ? '#' : res;
    }
 
};