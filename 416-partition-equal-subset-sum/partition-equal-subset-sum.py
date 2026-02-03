class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # basically it is about can we partition it  two or not

        # recursively calling

        if sum(nums)%2!=0:
            return False
        dp={}

        def dfs(i,target):
            if i>=len(nums):
                return target==0
            if target < 0:
                return False
            key=(i,target)
            if key in dp:
                return dp[key]
            dp[key]=dfs(i+1,target) or dfs(i+1,target-nums[i])
            return dp[key]

        return dfs(0,sum(nums)//2)

        
        