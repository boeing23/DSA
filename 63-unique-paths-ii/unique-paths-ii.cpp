class Solution {
    vector<vector<int>>directions={{1,0},{0,1}};
    vector<vector<int>>dp;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        dp.assign(row,vector<int>(col+1,-1));

        return dfs(0,0,row,col,obstacleGrid);
    }
    int dfs(int r, int c, int m, int n,vector<vector<int>>&grid )
    {
        if(r>=m || c>=n) return 0;
        if(grid[r][c]==1) return 0;
        if(r==m-1 && c==n-1)
        {
            return 1;
        }
        if(dp[r][c]!=-1) return dp[r][c]; 

        

        
            dp[r][c]=dfs(r+1,c,m,n,grid)+dfs(r,c+1,m,n,grid);
        

        return dp[r][c];
    }
};