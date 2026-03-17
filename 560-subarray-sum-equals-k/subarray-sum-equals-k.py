class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # basically the logic here is

        # [1,2,3,4,5]

        # you keep on taking the prefix sum of each index then to get how many targeted sums where there
        # you do is current sum-k this will tell you 

        sumMap=defaultdict(int)
        sumMap[0]=1
        prefix=0
        count=0
        for i in range(len(nums)):
            prefix+=nums[i]
            
            count+=sumMap[prefix-k]
            sumMap[prefix]+=1
        return count
        



        