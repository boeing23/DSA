class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        # basically in the first pass you create a prefix

        # meaningyou get the multiplication of every number before it

        prefix_mul=[1]*(len(nums))
        #prefix_mul[0]=nums[0]

        for i in range(1,len(nums)):

            prefix_mul[i]=prefix_mul[i-1]*nums[i-1]

        #now you have the multiplication of numbers before it

        after=1
        ans=[1]*len(nums)


        for i in range(len(nums)-1,-1,-1):
            ans[i]=after*prefix_mul[i]
            after*=nums[i]

        return ans










        