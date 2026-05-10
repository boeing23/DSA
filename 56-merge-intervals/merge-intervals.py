class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:


        # sort them as per their start


        intervals.sort(key=lambda x:x[0])

        ans=[]

        for start,end in intervals:

            if ans and ans[-1][1]>= start:
                ans[-1][1]=max(ans[-1][1], end)
            else:

                ans.append([start,end])

        return ans







        