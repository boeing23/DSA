class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        seen_map=defaultdict(int)

        for i in range(len(nums)):

            diff=target-nums[i]

            if diff in seen_map:
                return [seen_map[diff],i]
            seen_map[nums[i]]=i
        return []

        