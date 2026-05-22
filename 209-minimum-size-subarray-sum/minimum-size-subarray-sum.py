class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:

        l=0
        res=float('inf')
        windowSum=0
        for r in range(len(nums)):

            windowSum+=nums[r]


            #basically the window should keep on adding until

            #you shrink the window until it becomes taget's sum
            while windowSum>=target:
                if r-l+1<res:
                    res=r-l+1
                windowSum-=nums[l]
                l+=1

           #now res should only be calculated when the window is valid

                
            
            
            print(res)

        return res if res!=float('inf') else 0
        