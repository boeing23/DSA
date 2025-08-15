class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        frq={}

        for i in s:
            if i in frq:
                frq[i]+=1
            else:
                frq[i]=1
        for i in t:
            if i in frq:
                frq[i]-=1
            else:
                return False
        for count in frq.values():
            if count!=0:
                return False
        return True

