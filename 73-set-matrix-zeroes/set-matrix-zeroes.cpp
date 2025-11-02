class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();


        vector<bool>Zrow(row,false); //we will know what row val is 0;
        vector<bool>Zcol(col,false);


        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                if(matrix[r][c]==0)
                {
                    Zrow[r]=true;
                    Zcol[c]=true;
                }
            }
        }

        
        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                if(Zrow[r] || Zcol[c])
                {
                    matrix[r][c]=0;
                }
            }
        }
        

        
    }
};