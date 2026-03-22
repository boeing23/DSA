class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:


        if sum(nums)%p==0:
            return 0

        remainder_index=defaultdict(int)

        remainder_index[0]=-1
        total=sum(nums)%p
        prefix=0
        ans=len(nums)

        for i in range(len(nums)):
            prefix+=nums[i]

            current_rem=prefix%p

            target=(current_rem-total)%p
        
            if target in remainder_index:
                ans=min(ans,i-remainder_index[target])
            
            
            remainder_index[current_rem]=i
        return ans if ans< len(nums) else -1



        