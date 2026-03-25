class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # now basically in this we know one thing that one part is always sorted and target les in that part
        # once we find that part we can do a binary search on it


        # okay so how can we do it

        left=0
        right=len(nums)-1

        while left<=right:
            mid=(left+right)//2

            if nums[mid]==target:
                return mid

            elif nums[left]<=nums[mid]:
                if nums[left]<=target<nums[mid]:
                    right=mid-1
                else:
                    left=mid+1
            else:
                if nums[mid]<target<=nums[right]:
                    left=mid+1
                else:
                    right=mid-1

        return -1
        