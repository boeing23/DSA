class Solution {
public:
void solve(vector<vector<int>>&ans, vector<int>&ds, int frq[],vector<int>&nums)
{
    if(ds.size()==nums.size())
    {
        ans.push_back(ds);
    }

    for(int i=0;i<nums.size();i++)
    {
        if(!frq[i])
        {
            frq[i]=1;
            ds.push_back(nums[i]);
            solve(ans,ds,frq,nums);
            frq[i]=0;
            ds.pop_back();
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
    vector<vector<int>>ans;
    int n=nums.size();
    int frq[n];

    for(int i=0;i<nums.size();i++) frq[i]=0;

    solve(ans,ds,frq,nums);
    return ans;
        
    }
};