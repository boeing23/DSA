class Solution {

vector<pair<int, int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
public:
    void solve(vector<vector<char>>& board) {


        capture(board);

        for(int r=0;r<board.size();r++)
        {
            for(int c=0;c<board[0].size();c++)
            {
                if(board[r][c]=='O') board[r][c]='X';
                else if(board[r][c]=='T') board[r][c]='O';

            }
            
        }

        
    }

    void capture(vector<vector<char>>& board)
    {
        int row=board.size();
        int cols=board[0].size();
        queue<pair<int,int>>q;


        for(int r=0;r<row;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(r==0 || r==row-1 || c==0 || c==cols-1 && board[r][c]=='O')
                {
                    q.push({r,c});
                }

            }
        }

        while(!q.empty())
        {
            auto[r,c]=q.front();
            q.pop();
            if(board[r][c]=='O')
            {
                board[r][c]='T';
            
            for(auto &dir:directions)
            {
                int nr=r+dir.first;
                int nc=c+dir.second;
                if(nr>=0 && nr<row && nc>=0 && nc<cols)
                {
                    q.push({nr,nc});
                }
            }
            }
        }
    }
};
