class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        if(nums.size()<3) return {};
 

        for(int i=0;i<nums.size()-2;i++)
        {
           
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // pruning: if anchor > 0, no further triplets can sum to 0
        if (nums[i] > 0) break;
            
            int target=-nums[i];

            int l=i+1;
            int r=(int)nums.size()-1;
        
           

            while(l<r)
            {
                if(nums[l]+nums[r]<target) l++;
                else if(nums[l]+nums[r]>target) r--;

                else{
                    res.push_back({nums[i],nums[l],nums[r]});
                    int left=nums[l];
                    int right=nums[r];

                    while(l<r && nums[l]==left) l++;
                    while(l<r && nums[r]==right) r--;



                }

            }

            
        }
        return res;

        

        
    }
};