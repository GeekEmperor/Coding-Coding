class Solution {
public:
<<<<<<< HEAD
    int pivotIndex(vector<int>& nums) {
        int sum = 0, part = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            sum += nums[i];
        for (int i = 0; i < n; ++i) {
            if (sum - nums[i] == part * 2)
                return i;
            part += nums[i];
        }
        return -1;
=======
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
        
>>>>>>> 4eaf30f8958eaf6d9007a8cd41a35c43e348ff63
    }
};