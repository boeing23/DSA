class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        frqMap=Counter(nums)

        for key,val in frqMap.items():
            if val > len(nums)//2:
                return key
        return 0 
        