class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        n=1
        m=len(nums)
        l=0

        for i in range(1,m):
            # you only add when l-n+1<3 and nums[i]!=

            if nums[i]==nums[n-1]:
                if n-l<2:
                    nums[n]=nums[i]
                    n+=1
                
            else:
                l=n
                nums[n]=nums[i]
                n+=1
        return n

            