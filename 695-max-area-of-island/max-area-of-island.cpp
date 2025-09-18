class Solution {
    int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
int dfs(vector<vector<int>>& grid, int r,int c)
{
    if(r>=grid.size()||c>=grid[0].size()||grid[r][c]==0) return 0;

    
    grid[r][c]=0;
    int area=1;

    for(int i=0;i<4;i++)
    {
        area+=dfs(grid,r+direction[i][0],c+direction[i][1]);
    }

    return area;
    

    

    
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int row=grid.size();
        int col=grid[0].size();
        int maxA=0;
       


        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                if(grid[r][c]==1)
                {
                    maxA=max(maxA,dfs(grid,r,c));

                }
                
            }
        }

        return maxA;
        
    }
};
