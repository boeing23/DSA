class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:


        #basicalyy it is a sliding window problem, 
        
        l=0
        #a frq map to store the unique chars in the window

        countP=Counter(p)
        window=defaultdict(int)

        #haves and needs== then store the l and do +1
        need=len(countP)
        have=0
        ans=[]


        for r in range(len(s)):
            # //now in the window i have to keep the count of elements

            # so anagrams mean elements for that window the frq of

            window[s[r]]+=1
            #now you have to keep this window len up to the len of p
            if r-l+1>len(p):
                window[s[l]]-=1
                if window[s[l]]==0:
                    del window[s[l]]
                l+=1
            if r-l+1==len(p):
                if window==countP:
                    ans.append(l)
                    
                
        return ans





            