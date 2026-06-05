class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ones=0
        n=len(nums)
        maxO=0

        for r in range(n):
            if nums[r]==1:
                ones+=1
            else:

                ones=0
            maxO=max(ones,maxO)
        return maxO
        