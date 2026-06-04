class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        open=0
        close=0
        ans=[]
        result=[]
#how can I know the stray locations 
        for c in s:
            if c=='(':
                #it is an open bracket
                open+=1
            if c==')':
                if open>0:
                    open-=1
                else:
                    continue
            ans.append(c)
        for c in ans[::-1]:
            if c=="(" and open>0:
                open-=1
                continue
            result.append(c)




        

        return ''.join(reversed(result))