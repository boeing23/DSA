class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # sort with the first element
        # then all the starts come together 
        # 1,3] 2,6] 8,10] 15,18]
        intervals.sort()

        #now traverse through each interval
        ans=[]
        for i in range(len(intervals)):
            if len(ans)==0 or intervals[i][0]>ans[-1][1]:
                ans.append(intervals[i])
            else:
                ans[-1][1]=max(intervals[i][1], ans[-1][1])
        return ans


        

        