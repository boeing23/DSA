class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:


        # my world knows that 

        # to get the middle part of the subarray it means you have to store 
        # prefix sum so for nums[4] the subarray sum=nums[0]+nums[1]+nums[2]+nums[3]

        # now let's say i need the sum between 2:3. i would do nums[4]-nums[2]

        # now let's tale of multiple of k, multiple of k means it should be divisible by k
        # so basically let's take 23+2, 29+6=35
        # 5 30 now i have to see if there was any remainder 4 before this

        


        prefix=0
        remainder_count=defaultdict(int)
        remainder_count[0]=-1
        if len(nums)<2:
            return False

        for i in range(len(nums)):
            prefix+=nums[i]
            remainder=prefix%k

            if remainder in remainder_count:
                if i-remainder_count[remainder]>=2:
                    return True
            else:
                remainder_count[remainder]=i
        return False


        