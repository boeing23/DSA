class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax=0;
        int best=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(currMax<0) currMax=0;
            currMax+=nums[i];
            best=max(best,currMax);
        }
        return best;
        
    }
};