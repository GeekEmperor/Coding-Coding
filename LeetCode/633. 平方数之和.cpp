class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        for(int i=sqrt(c);i>=0;i--)
        {
           int j=sqrt(c-i*i);
           if(j*j==c-i*i)
               return 1;
        }
        return 0;
    }
};