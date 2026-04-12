class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:


        frqMap=Counter(nums1)
        ans=[]

        for n in nums2:

            if frqMap.get(n,0)>0:
                ans.append(n)
                frqMap[n]-=1
        return ans
        