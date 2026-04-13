class Solution:
    def rob(self, nums: List[int]) -> int:


    #     this one uses a flag

    # basically the idea of flag is you start with False and only change it to true when you rob house 0, now whenever a next house is called it remains same, whatever it received from the parent
        dp=defaultdict(int)
        def dfs(idx,flag)->int:
            if idx>=len(nums):
                return 0

            if flag and idx==len(nums)-1:
                return 0
            if (idx,flag) in dp:
                return dp[(idx,flag)]
            dp[(idx,flag)]=max(nums[idx]+dfs(idx+2,idx==0 or flag),dfs(idx+1, flag))

            return dp[(idx,flag)]

            

        


        return dfs(0,False)


        