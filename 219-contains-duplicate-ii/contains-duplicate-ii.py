class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:


        indexMap=defaultdict(int)

        for i in range(len(nums)):

            if nums[i] in indexMap and i-indexMap[nums[i]]<=k:
                return True
            indexMap[nums[i]]=i

        return False
        