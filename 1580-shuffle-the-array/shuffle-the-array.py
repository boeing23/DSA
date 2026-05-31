class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        ans=[0]*2*n
        l=0
        r=1

        

        for i in range(n):
            ans[l]=nums[i]
            l+=2
            ans[r]=nums[i+n]
            r+=2
        return ans
        