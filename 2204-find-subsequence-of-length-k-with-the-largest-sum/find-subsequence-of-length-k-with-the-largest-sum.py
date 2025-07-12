class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        arr=[(num,i) for i, num in enumerate(nums)]
        arr.sort(reverse=True, key=lambda x: (x[0], -x[1]))
        top_k=sorted(arr[:k], key=lambda x:x[1])
        return [num for num,_ in top_k]
        