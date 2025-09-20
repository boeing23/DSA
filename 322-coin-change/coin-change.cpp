class Solution {
    vector<vector<int>>dp;
    const int INF = 1e9;
public:
    int coinChange(vector<int>& coins, int amount) {

        //memoize for i and at that time what was the amount, it is normal take not take
        dp.assign(coins.size(), vector<int>(amount + 1, -1));

        int ans=dfs(coins,amount,0);
     return (ans >= INF) ? -1 : ans;

         

        
        
    }

    int dfs(vector<int>& coins, int amount, int i)
    {
        if(amount==0) return 0;
        if (i == (int)coins.size() || amount < 0) return INF;
        if(dp[i][amount]!=-1) return dp[i][amount];
        
        return dp[i][amount]=min(1+dfs(coins,amount-coins[i],i),dfs(coins,amount,i+1));
    }


};