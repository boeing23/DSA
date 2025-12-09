class Solution {

    vector<vector<int>>res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int start=0;

        vector<int>sub;

        dfs(candidates,target, start, sub);
        return res;
        
    }

    void dfs(vector<int>& nums, int target, int start, vector<int>sub)
    {
        if(target==0)
        {
            res.push_back(sub);
            return;
        }
        if(target<0) return;

        for(int end=start;end<nums.size();end++)
        {
            sub.push_back(nums[end]);
            dfs(nums,target-nums[end], end,sub);
            sub.pop_back();

        }


    }
};