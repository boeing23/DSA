class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # we will use bucket sort for this, basically indexes is the frq and it stores the number of it

        # for example take this
        # [1,1,1,2,2,3]

        # now frq of 1 is 3
        # it goes to the location 3 and stores 1

        # so first we need the frq of each


        frqmap=Counter(nums)
        buckets= [[] for _ in range(len(nums)+1)]

        #now it is possible that two nums can have same frq

        for key,val in frqmap.items():
            buckets[val].append(key)
        ans=[]
        
        for i in range(len(buckets)-1, 0,-1):
            for n in buckets[i]:
                ans.append(n)
            if len(ans)==k:
                return ans
        return ans

        # []
        # []
        # []
        # []
