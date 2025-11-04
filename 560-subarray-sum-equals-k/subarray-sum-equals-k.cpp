class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int>sumf;
        int sum=0;
        int ans=0;
        sumf[0]=1;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sumf.count(sum-k)) ans+=sumf[sum-k];

            sumf[sum]++;
        }
return ans;
        
    }
};