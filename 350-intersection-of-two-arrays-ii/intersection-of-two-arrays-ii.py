class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:

        count1=Counter(nums1)
        count2=Counter(nums2)
        ans=[]


        for n in count1:
            if n in count1 and n in count2:
                frq=min(count1[n],count2[n])
                while frq:
                    ans.append(n)
                    frq-=1
        return ans

        