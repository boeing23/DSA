class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        # basically in this question we have to remove the interval which ends late

        # so to do this we can first sort the intervals then the intervals with closer starts are clubbed together

        intervals.sort()


        prevEnd=intervals[0][1]
        res=0


        for start,end in intervals[1:]:
            if start>=prevEnd:
                prevEnd=end
            else:
                prevEnd=min(end,prevEnd)
                res+=1

        return res



        