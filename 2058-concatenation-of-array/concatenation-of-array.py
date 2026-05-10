class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:

        l=len(nums)+len(nums)

        ans=[0]*l
        n=len(nums)

        for i in range(len(nums)):
            ans[i]=nums[i]
            ans[i+n]=nums[i]

        return ans
        