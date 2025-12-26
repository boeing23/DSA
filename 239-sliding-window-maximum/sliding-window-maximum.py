class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # the idea is to store max in the q. so q.front is always bigger than the elements at bck
        q=deque()
        l=r=0
        res=[]

        while r<len(nums):

            while q and nums[q[-1]]<nums[r]:
                q.pop()
            q.append(r)

            if l>q[0]:
                q.popleft()

            if (r+1)>=k:
                res.append(nums[q[0]])
                l+=1
            r+=1

        return res
            
            

                

        