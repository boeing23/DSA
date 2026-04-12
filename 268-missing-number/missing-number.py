class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        

        # it is for sure binary search problem


        # you have a 

        nums.sort()
        lo=0
        hi=len(nums)

        

        while lo<hi:

            mid=(lo+hi)//2

            if nums[mid]>mid:
                hi=mid
            else:
                lo=mid+1
        return lo
