class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:


        lo=0
        hi=len(nums)-1
        if_not=0

        while lo<=hi:
            mid=(lo+hi)//2

            if nums[mid]==target:
                return mid
            elif nums[mid]<target:
                lo=mid+1
            else:
                if_not=mid
                hi=mid-1
        return lo
        