class Solution:
    def mySqrt(self, x: int) -> int:
        if x<2:
            return x
        

        lo=1
        hi=x//2
        ans=0

        while lo<=hi:

            mid=(lo+hi)//2

            if mid*mid==x:
                return mid
            elif mid*mid<x:
                ans=mid
                lo=mid+1
            else:
                hi=mid-1
        return ans
        