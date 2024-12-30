class Solution {
public:
    int dp[100001];
    int MOD = 1000000007;
    int solve(int len,int &one, int &zero,int &low, int &high)
    {
        if(len>high)
        {
            return 0;
        }
        if(dp[len]!=-1) return dp[len];
        
        int res=0;
        if(len>=low) res++;
        
        res+=solve(len+zero,one,zero,low,high);
        res+=solve(len+one,one,zero,low,high);

        return dp[len]=res % MOD;
    }

   
    

    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return solve(0,one,zero,low,high);
        
       
    }

};
