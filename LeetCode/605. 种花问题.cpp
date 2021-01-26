class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int count=0;
        if(flowerbed[0]==0&&flowerbed[1]==0)
        {
            flowerbed[0]=1;
            count++;
        }
        for(int i=1;i<flowerbed.size()-1;i++)
            if(flowerbed[i-1]==0&&flowerbed[i]==0&&flowerbed[i+1]==0)
            {
                flowerbed[i]=1;
                count++;
            }
        if(flowerbed[flowerbed.size()-2]==0&&flowerbed[flowerbed.size()-1]==0)
        {
            flowerbed[flowerbed.size()-1]=1;
            count++;
        }
        return count>=n;
    }
};