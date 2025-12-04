class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows=matrix.size();
        int cols=matrix[0].size();


        vector<bool>Zrow(rows,false);
        vector<bool>Zcol(cols,false);

        


        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(matrix[r][c]==0)
                {
                    Zrow[r]=true;
                    Zcol[c]=true;
                }
            }
        }

        
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(Zrow[r] || Zcol[c])
                {
                    matrix[r][c]=0;
                }
            }
        }
        

        

        
    }
};