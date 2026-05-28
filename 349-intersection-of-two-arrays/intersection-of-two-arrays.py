class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1set=set(nums1) #[1,2]
        nums2set=set(nums2) #[2]
        ans=[]

        for n in nums1set:
            if n in nums1set and n in nums2set:
                ans.append(n)

        return ans