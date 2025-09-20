class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);

        int skip=dfs(nums,dp1,0);
        int take=dfs(nums,dp2,1);
        return max(skip,take);

        
    }

    int dfs(vector<int>& nums, vector<int>& dp, int i)
    {
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int skip=dfs(nums,dp,i+1);
        int take=nums[i]+dfs(nums,dp,i+2);


        return dp[i]=max(skip,take);


    }
};