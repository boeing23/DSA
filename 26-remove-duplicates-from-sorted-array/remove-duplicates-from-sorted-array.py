class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:


        # 1,2,1

        # wht if instead of removing i just push all the duplicates at the end
        # and keep k as the len of uniq
        k=1

        for i in range(1,len(nums)):
            if nums[k-1]!=nums[i]:
                nums[k]=nums[i]
                k+=1
        return k
        

       

        