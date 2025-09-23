class Solution {
    vector<vector<int>>dp;
public:
    int lengthOfLIS(vector<int>& nums) {

        dp.assign(nums.size(),vector<int>(nums.size()+1,-1));
        

        return findSubsequence(nums,0,-1);

        
    }

    int findSubsequence(vector<int>& nums,int i, int prev)
    {
        if(i>=nums.size()) return 0;

        if(dp[i][prev+1]!=-1)  return dp[i][prev+1];//dp condition yet to be decided;
        //what if the small number arrives that condition
         int take=0;
        if(prev == -1 ||nums[i]>nums[prev])
        {
            take=1+findSubsequence(nums,i+1,i);

        }
        
        int nottake=findSubsequence(nums,i+1,prev);

        return dp[i][prev+1]=max(take,nottake);
    }



};