class Solution {
public:
int solve(vector<int>&coins, int amount, int ind, vector<vector<int>>&dp)
{
    if(ind>=coins.size()|| amount<0)
    {
        return INT_MAX;
    }
    if(amount==0)
    {
        return 0;
    }
    if(dp[ind][amount]!=-1)
    {
        return dp[ind][amount];
    }
   int take=INT_MAX;
    if(coins[ind]<=amount)
    {
        take=solve(coins,amount-coins[ind],ind,dp);
        if(take!=INT_MAX) take=1+take;

    }

    int nottake=solve(coins,amount,ind+1,dp);
 
 return dp[ind][amount]=min(take,nottake);

}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int res=solve(coins,amount,0,dp);
        if(res!=INT_MAX)
        {
            return res;
        }
        else
        {
            return -1;
        }
    }
};