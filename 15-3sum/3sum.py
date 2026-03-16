class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        # basically in this question i have to take a number and now i have to find it's triplets in the
        # remaining subspace using two pointers


        nums.sort()       #Now this will bring the duplicates together and the search space would be optimal

        ans=[]

        for i,n in enumerate(nums):

            
            l=i+1
            r=len(nums)-1
            if i>0 and nums[i-1]==nums[i]:
                continue
            
            while l<r:
                total=n+nums[l]+nums[r]

                if total>0:
                    r-=1
                elif total<0:
                    l+=1
                elif total==0:
                    ans.append([n,nums[l],nums[r]])
                    l+=1
                    r-=1
                    while l<r and nums[l]==nums[l-1]:
                        l+=1
                    while l<r and nums[r]==nums[r+1]:
                        r-=1
                
        return ans


        