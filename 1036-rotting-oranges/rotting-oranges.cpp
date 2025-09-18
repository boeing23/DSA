class Solution {
    
public:
    int orangesRotting(vector<vector<int>>& grid) {


        int fresh=0;
        int time=0;
        int rot=0;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int,int>>q;
        for(int r=0;r<grid.size();r++)
        {
            for(int c=0;c<grid[0].size();c++)
            {
                if(grid[r][c]==1)
                {
                    fresh++;
                }
                else if(grid[r][c]==2)
                {
                    
                    q.push({r,c});
                }
            }
            
        }


        while(fresh>0 && !q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto[row,col]=q.front();
                q.pop();

            for(const auto&dir: directions)
            {
                int nr=row+dir.first;
                int nc=col+dir.second;

                 
                    

                    if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==1)
                    {
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        fresh--;

                    }
                


            }
            
            }
            time++;
            
        }
return fresh == 0 ? time : -1;
        
        
    }
};
