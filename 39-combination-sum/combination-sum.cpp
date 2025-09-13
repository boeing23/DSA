class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>>res;

        vector<int>sub;

        dfs(nums,res,sub, target, 0,0);
        return res;
        
    }


void dfs(vector<int>& nums,vector<vector<int>>&res, vector<int>&sub, int target, int i, int sum)
    {
        if(target==sum)
        {
            res.push_back(sub);
            return;
        }

        if(sum>target || i>=nums.size()) return;

        sub.push_back(sum+nums[i]);
        dfs(nums,res,sub, target-nums[i],i,sum);
        sub.pop_back();
        dfs(nums,res,sub, target,i+1,sum);

        

        
        

    }
};