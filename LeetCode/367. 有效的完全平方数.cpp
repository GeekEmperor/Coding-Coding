class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        int x1,x2 = num;
        do
        {
            x1 = x2;
            x2 = (x2+num/x2)/2;
        } while((x1-x2)>1||(x2-x1)>1);
        return (num==x2*x2);
    }
};