class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_set<int>set;

        for(int i=0;i<nums.size();i++)
        {
            if(!set.count(nums[i])) set.insert(nums[i]);
            else return nums[i];
        }

        return 0;
    }
};