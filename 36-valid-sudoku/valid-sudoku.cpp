class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9);
        unordered_map<string, unordered_set<char>> boxes;

        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                char ch=board[r][c];
                if(ch=='.') continue;
                string b= to_string(r/3)+ to_string(c/3);


                if(rows[r].count(ch) || cols[c].count(ch) || boxes[b].count(ch)) return false;
                rows[r].insert(ch);
                cols[c].insert(ch);
                boxes[b].insert(ch);
            }
        }

        return true;

        
    }
};