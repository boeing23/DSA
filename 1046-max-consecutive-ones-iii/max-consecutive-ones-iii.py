class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        # window should hold all the 1 with max levy of k 0s
        # and suddenly if the window is invalid you move the lfet

        l=0
        ones=0
        maxL=0

        for r in range(len(nums)):
            if nums[r]==1:
                ones+=1
            


            while (r-l+1)-ones>k:
                if nums[l]==1:
                    ones-=1

                l+=1
            maxL=max((r-l+1),maxL)
        return maxL
        