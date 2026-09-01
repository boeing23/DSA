class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:


        l=0
        maxheap=[]
        ans=[]

        for r in range(len(nums)):
            heapq.heappush(maxheap,(-nums[r], r))
            while maxheap[0][1]<r-k+1:
                heapq.heappop(maxheap)
            

            if r-l+1==k:
                ans.append(-maxheap[0][0])
                l+=1
        return ans
            


            

        