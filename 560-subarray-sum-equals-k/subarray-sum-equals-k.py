class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:


        Rsum=0
        count=0
        indexMap=defaultdict(int)
        indexMap[0]=1
    
        for i in range(len(nums)):
            Rsum+=nums[i]
            diff=Rsum-k
            if diff in indexMap:
                count+=indexMap[diff]
            indexMap[Rsum]+=1
        return count




        