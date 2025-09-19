class Solution {
    vector<vector<int>>res;
public:

void solve(vector<int>& nums, vector<int>& sub, int i)
{
    res.push_back(sub);
for(int end=i;end<nums.size();end++)
{
    sub.push_back(nums[end]);
    solve(nums,sub,end+1);
    sub.pop_back();

}
    
    
    
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>sub;

        solve(nums,sub,0);

        return res;

        
    }
};