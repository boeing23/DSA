class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int l=0;
        int maxS=INT_MIN;
        int sum=0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];

            

            maxS=max(maxS, sum);

            if(sum<0)
            {
                sum=0;
            }
        }


        return maxS;
        
    }
};