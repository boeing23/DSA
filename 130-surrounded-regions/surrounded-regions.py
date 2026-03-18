class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row=len(board)
        col=len(board[0])
        directions=[[1,0],[-1,0],[0,1],[0,-1]]

        
        def capture():
            q=deque()
            for r in range(row):
                for c in range(col):
                    if (r==0 or r==row-1 or c==0 or c==col-1) and board[r][c]=='O':
                        board[r][c]='T'
                        q.append([r,c])
            while q:
                r,c=q.popleft()

                for nr,nc in directions:
                    newR=r+nr
                    newC=c+nc

                    if (0<=newR<row and 0<=newC<col) and board[newR][newC]=='O':
                        board[newR][newC]='T'
                        q.append([newR,newC])
        capture()
        for r in range(row):
            for c in range(col):
                if board[r][c]=='O':
                    board[r][c]='X'
                if board[r][c]=='T':
                    board[r][c]='O'
                


