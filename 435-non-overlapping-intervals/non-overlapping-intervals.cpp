class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b) {
         
         return a[1] < b[1]; 
});

int prevEnd=intervals[0][1];

int count=0;

for(int i=1;i<intervals.size();i++)
{
    int currEnd=intervals[i][1];
    int currStart=intervals[i][0];

    if(currStart<prevEnd)
    {
        count++;
    }
    else{
        prevEnd=currEnd;

    }
    

}

return count;

        
    }
};