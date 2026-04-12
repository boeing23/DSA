class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        ans=[]

        for n in nums:
            idx=abs(n)-1

            if nums[idx]>0:
                nums[idx]=-nums[idx]
        for i in range(len(nums)):
            if nums[i]>0:
                ans.append(i+1)

        return ans
                