class Solution {
public:
bool solve(vector<int>&nums,int ind, int sum1,int target,vector<vector<int>>&dp)
{
    if(ind>=nums.size()||sum1>target)
    {
        return 0;
    }
    if(sum1==target)
    {
        return true;
    }
    if(dp[ind][sum1]!=-1)
    {
        return dp[ind][sum1];
    }

   bool take= solve(nums,ind+1,sum1+nums[ind],target,dp);
   bool nott=solve(nums,ind+1,sum1,target,dp);

   return dp[ind][sum1]=take||nott; 
}

    bool canPartition(vector<int>& nums) {
        int sum1=0;
        int sum2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum2+=nums[i];
        }
        if(sum2%2!=0)
        {
            return false;
        }
        int target=sum2/2;
         vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1)); 

        return solve(nums,0,sum1,target,dp);
        
    }
};