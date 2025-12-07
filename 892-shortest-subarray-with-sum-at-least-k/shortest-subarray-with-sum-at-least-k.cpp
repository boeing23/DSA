class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        vector<long long>prefix(nums.size()+1,0);
        int sum=0;

        for(int i=0;i<nums.size();i++)
        {
            
            prefix[i+1]=prefix[i]+nums[i];
        }

        deque<int>dq;
        int ans=INT_MAX;

        for(int i=0;i<prefix.size();i++)
        {
            while(!dq.empty() && prefix[i]-prefix[dq.front()]>=k)
            {
                ans=min(ans,i-dq.front());
                dq.pop_front();

            }
            while(!dq.empty() && prefix[i]<=prefix[dq.back()])
            {
                dq.pop_back();

            }



            dq.push_back(i);
        }
return ans==INT_MAX ? -1 : ans;

        
    }
};