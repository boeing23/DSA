class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int Row=matrix.size();
        int col=matrix[0].size();

        int top=0;
        int bot=Row-1;


        while(top<=bot)
        {
            int row=(top+bot)/2;
            if(target>matrix[row][col-1])
            {
                top=row+1;
            }
            else if(target<matrix[row][0])
            {
                bot=row-1;
            }
            else break;
        }


        int row=(top+bot)/2;
        if (!(top <= bot)) {
            return false;
        }

        int l=0;
        int r=col-1;


        while(l<=r)
        {
            int mid=(l+r)/2;

            if(target>matrix[row][mid]) l=mid+1;
            else if(target<matrix[row][mid]) r=mid-1;
            else return true;
        }


        return false;


    

        
        
    }
};