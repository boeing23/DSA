class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {


        //we are supposed to rotate an image. 
        //in place rotation which means there should be a point to swap the values;
        //how to transpose the matrix
    //so here I had a problem of how to shift digonally

    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<i;j++)  //j less than i ensures it do not swap the same element for example consider a scenarion i=j then?
        {
            swap(matrix[i][j], matrix[j][i]);
        }


    }

    for(int i=0;i<matrix.size();i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
        
    }
};