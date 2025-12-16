class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int direction=1;
        vector<int>ans;
        int r=0;
        int c=0;

        while(r<row && c<col)
        {
            ans.push_back(mat[r][c]);
            int nr= r+ (direction==1?-1:1);
            int nc=c+ (direction==1?1:-1);

            if(nr<0 || nr>=row || nc<0 || nc>=col)
            {
                if(direction ==1)
                {
                    if(c>=col-1)
                    {
                        r=r+1;
                    }
                    else
                    {
                        c=c+1;
                    }
                }
                else
                {
                    if(r>=row-1)
                    {
                        c=c+1;
                    }
                    else
                    {
                        r=r+1;
                    }
                }
                if(direction==1)
                {
                    direction=0;
                }
                else
                {
                    direction=1;
                }

            }
            else{
                r=nr;
            c=nc;

            }

            

            
        }

        return ans;
        
    }
};