class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        frqMap=Counter(nums)
        l=len(nums)
        buckets=[[]for _ in range(l+1)]

        for key,val in frqMap.items():
            buckets[val].append(key)
        ans=[]
        #first get inside bucket
        n=len(buckets)
        # [   
        #     3->[1,2]
        #     2->[3]


        # ]
        # start from the back then when inside that bucket you start appending to ans until k
        for i in range(n-1,0,-1):
            curr_bucket= buckets[i] #this is a list and now we should traverse this too 
            for m in curr_bucket:
                ans.append(m)
                if len(ans)==k:
                    return ans
        return ans
                



        # 1->3
        # 2->2
        # 3->1
        