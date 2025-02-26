class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

       int maxF=nums[0];
       int sum1=nums[0];

       for(int i=1;i<nums.size();i++)
       {
        maxF=max(maxF+nums[i],nums[i]);
        sum1=max(sum1,maxF);

        
       }

       int minF=INT_MAX;
       int diff=INT_MAX;


       for(int i=0;i<nums.size();i++)
       {
        if(minF>0)
        {
            minF=nums[i];

        }
        else
        {
            minF+=nums[i];
        }
        diff=min(minF,diff);
       }


       int ans=max(abs(sum1),abs(diff));

       return ans;
    }
};