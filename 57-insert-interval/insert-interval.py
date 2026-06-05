import bisect

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        index=bisect.bisect_left(intervals,newInterval)
        # index tells me the first index which can be inserted at the pos
        # [1,3][4,6]

        # it gave me index 1
        # now i say append all the intervals before that index, now compare the
        # newInterval with the back
        # the back becomes 1,5 then next interval comes it checks
       
        ans=(intervals[:index])
        if ans and ans[-1][1]>=newInterval[0]:
            ans[-1][1]= max(ans[-1][1], newInterval[1])
        else:
            ans.append(newInterval)
        print(ans)


        for interval in intervals[index:]:
            if interval[0]<= ans[-1][1]:
                ans[-1][1]=max(interval[1], ans[-1][1])
            else:
                ans.append(interval)

        return ans