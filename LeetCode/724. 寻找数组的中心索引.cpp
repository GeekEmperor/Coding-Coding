class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        if(nums.size()==0||nums.size()==2)
            return -1;
        if(nums.size()==1)
            return 0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            if(2*x==sum-nums[i])
                return i;
            x+=nums[i];
        }
        return -1;
        
    }
};