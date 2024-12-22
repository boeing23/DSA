class Solution {

    vector<int>segT;
void buildSegmentTree(vector<int>& heights,int start,int end,int st_idx){
    if(start==end){
            segT[st_idx]=start;
            return;
        }

        int mid = start + (end-start)/2;
        buildSegmentTree(heights,start,mid,2*st_idx);
        buildSegmentTree(heights,mid+1,end,2*st_idx+1);

        segT[st_idx] = heights[segT[2*st_idx]] >= heights[segT[2*st_idx+1]] ?
                       segT[2*st_idx] : segT[2*st_idx+1];
    }
    int rangeMaxQuery(vector<int>& heights,int qs,int qe,int start,int end,int st_idx=1){
        if(start>=qs and end<=qe)//Total Overlap
            return segT[st_idx];
        if(start>qe or end<qs)//No Overlap
            return INT_MIN;
        
        //Partial Overlap
        int mid = start + (end-start)/2;
        int left_max = rangeMaxQuery(heights,qs,qe,start,mid,2*st_idx);
        int right_max = rangeMaxQuery(heights,qs,qe,mid+1,end,2*st_idx+1);

        if(left_max==INT_MIN)   return right_max;
        if(right_max==INT_MIN)  return left_max;
        return heights[left_max] >= heights[right_max] ?
               left_max : right_max;
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {

                      vector<int>ans;
         int n = heights.size();
        segT = vector<int>(4*n+1);
        int st_idx=1;//Segment Tree Index: Root at index-1 segment tree implementations

        buildSegmentTree(heights,0,n-1,st_idx);

        vector<int> res;
        for(auto query: queries){
            int alice = min(query[0],query[1]);
            int bob = max(query[0],query[1]);

            if(alice==bob or heights[bob]>heights[alice]){
                res.push_back(bob);
                continue;
            }
            //Binary Search + RMQ (Range Max Query)
            int low = bob;
            int high = n-1;
            int ans=INT_MAX;
            while(low <= high){
                int mid = low + (high-low)/2;
                int rmq = rangeMaxQuery(heights,low,mid,0,n-1,st_idx);

                if(heights[rmq] > heights[alice]){
                    high = mid-1;
                    ans = min(ans,rmq);
                }else{
                    low = mid+1;
                }
            }
            if(ans==INT_MAX)    res.push_back(-1);
            else                res.push_back(ans);
        }
        return res;
    }
};

        