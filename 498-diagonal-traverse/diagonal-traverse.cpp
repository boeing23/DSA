class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int direction=1;

        int row=mat.size();

        int col=mat[0].size();
        int r=0;
        int c=0;



        vector<int>res;

        while(r<row && c<col)
        {
            res.push_back(mat[r][c]);

            int nr= r+ (direction == 1 ? -1 : 1);
            int nc= c+ (direction == 1 ? 1 : -1);

            if(nr<0 || nc<0 || nr>=row || nc>=col)
            {
                if(direction==1)
                {
                    if(c== col-1)
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
                    if(r==row-1)
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
                    direction =1;
                }
                

            }

            else{
                r=nr;
            c=nc;

            }

            
        }

        return res;

        //if nr<0 then go down, direction =0;


        
    }
};