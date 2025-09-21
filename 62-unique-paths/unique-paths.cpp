class Solution {
    vector<vector<int>>dp;
public:
    int uniquePaths(int m, int n) {

        dp.assign(m,vector<int>(n,-1));

        return dfs(0,0,m,n);


        
    }

    int dfs(int r, int c, int m, int n)
    {
        if(r==m-1 && c==n-1) return 1;
        if(r>=m || c>=n) return 0;

        if(dp[r][c]!=-1) return dp[r][c];

        return dp[r][c]=dfs(r+1,c,m,n)+dfs(r,c+1,m,n);
    }
};