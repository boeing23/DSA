class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        #so basically 100-1 exist karto ka, karat asel tar this cannot be the start

        unique=set(nums)
        maxL=0


        for n in unique:
            if n-1 not in unique:
                length=0
                while n+length in unique:
                    length+=1
                maxL=max(length,maxL)

        return maxL

        