class Solution {
    #define pii pair<int,int>
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<pii>a(m*n+1);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[mat[i][j]]=make_pair(i,j);

            }
        }

        vector<int>row(m,0);
        vector<int>col(n,0);

        for(int i=0;i<m*n;i++)
        {
            pii cord= a[arr[i]];
            int x=cord.first;
            int y=cord.second;

            row[x]++;
            col[y]++;

            if(row[x]==n || col[y]==m) return i;

        }
        return 0;
        
    }
};