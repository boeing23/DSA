class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // sort them based on to their head so that the closer intervals remain closer.

        // [1,3] [2,6] [8,10] [15,18]

        // okay now

        sort(intervals.begin(),intervals.end());

        //okay now closer elements stay close

        // now traverse 
        vector<vector<int>>ans;

        for(auto interval: intervals)
        {
            if(ans.empty() || ans.back()[1]<interval[0])
            {
                ans.push_back(interval);
            }
            else
            {
                ans.back()[1]=max(ans.back()[1],interval[1]);
            }
        }

        return ans;


        
    }
};