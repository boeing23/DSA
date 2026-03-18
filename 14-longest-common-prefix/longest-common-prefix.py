class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:

        ans=strs[0]

        for i in range(1,len(strs),1):
            
            curr=strs[i]
            j=0
            while j <min(len(curr),len(ans)):
                if curr[j]==ans[j]:
                    j+=1
                else:
                    break
            ans=ans[0:j]
            print(ans)
        return ans
            

        