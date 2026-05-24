class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        ans=[0,0]
        l= bisect.bisect_left(nums,target)
        if l<len(nums) and nums[l]==target:
            ans[0]=l
        else:
            ans[0]=-1

        r= bisect.bisect_right(nums,target)-1  #this would give the last occurence

        if r>=0 and nums[r]==target:
            ans[1]=r
        else:
            ans[1]=-1

        return ans
        