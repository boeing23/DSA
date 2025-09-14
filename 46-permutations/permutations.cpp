class Solution {
    vector<vector<int>>res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums,0);
        return res;
        
        
    }

    void perm(vector<int>& nums, int ind)
    {
        if(ind==nums.size()) 
        {
            res.push_back(nums);
            return;
        }

        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind],nums[i]);
            perm(nums,ind+1);
            swap(nums[ind],nums[i]);
        }



    }
};
