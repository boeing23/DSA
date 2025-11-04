class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int runningSum=0;
        unordered_map<int,int>runningInd;
        runningInd[0]=-1;

        for(int i=0;i<nums.size();i++)
        {
            runningSum+=nums[i];
            if(runningInd.count(runningSum%k)) 
            {
                if(i-runningInd[runningSum%k]>1) return true;
            } //checks if the remainder exists and what index it appeared
            else
            {
                runningInd[runningSum%k]=i;
            }
        }

        return false;
    }
};