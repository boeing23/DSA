class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:

        originalColor=image[sr][sc]
        if originalColor==color:
            return image
        
        def dfs(r,c):
            if image[r][c]!=originalColor:
                    return
            image[r][c]=color

            for dr,dc in [(1,0),(-1,0),(0,1),(0,-1)]:

                

                nr=r+dr
                nc=c+dc

                if 0<=nr<len(image) and 0<=nc<len(image[0]) and image[nr][nc]==originalColor:
                    dfs(nr,nc)

        #image[sr][sc]=color
        dfs(sr,sc)

        return image


