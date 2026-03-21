class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        #i will just store remainder and the index at which it occured
        prefix=0
        remainder_count=defaultdict(int)

        remainder_count[0]=1
        count=0


        for i in range(len(nums)):
            prefix+=nums[i]

            remainder=prefix%k
            count+=remainder_count[remainder]
            remainder_count[remainder]+=1
            
                
        return count




    #     now for this

    #    this is the subarray sum after one pass [0,4,9,9,7,4,5]

    #    now th task is to get suarrays sum divisible by k






        

