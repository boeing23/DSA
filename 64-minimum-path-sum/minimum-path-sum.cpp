class Solution {
    vector<vector<int>>dp;
    int INF=1e7;
public:
    int minPathSum(vector<vector<int>>& grid) {

dp.assign(grid.size(),vector<int>(grid[0].size(),-1));



return dfs(0,0,grid);
        
    }
    int dfs(int r,int c,vector<vector<int>>& grid)
    {
        if(r==grid.size()-1 && c==grid[0].size()-1) return grid[r][c];

        if(r>=grid.size() || c>=grid[0].size()) return INT_MAX/2;


        if(dp[r][c]!=-1) return dp[r][c];

        return dp[r][c]=grid[r][c]+min(dfs(r+1,c,grid),dfs(r,c+1,grid));


         
    }
};