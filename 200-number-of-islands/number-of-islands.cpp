class Solution {
    int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
void dfs(vector<vector<char>>& grid, int r, int c)
{
    if(r>=grid.size()||c>=grid[0].size()||grid[r][c]=='0') return;

    grid[r][c]='0';
    for(int i=0;i<4;i++)
    {
        dfs(grid,r+direction[i][0],c+direction[i][1]);
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int cols=grid[0].size();
        int islands=0;

        for(int r=0;r<row;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(grid[r][c]=='1')
                {
                    dfs(grid,r,c);
                    islands++;
                }
            }
        }

        return islands;
        
    }
};
