class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:

        prefixMap=defaultdict(int)
        prefixMap[0]=1
        count=0

        prefix=0

        for i in range(len(nums)):
            prefix+=nums[i]

            diff=prefix-k

            count+=prefixMap[diff]
            prefixMap[prefix]+=1
        return count
            

            # what do i store?
            # i see if this diff is already occured before or not
        