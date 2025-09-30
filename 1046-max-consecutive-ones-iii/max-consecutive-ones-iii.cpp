class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l=0;
        int res=0;
        int numszero=0;

        for(int r=0;r<nums.size();r++)
        {

            if(nums[r]==0)
            {
                numszero++;

            }

            while(numszero>k)
            {
                if (nums[l]==0) numszero--;
               l++;
            }

            res=max(r-l+1,res);



         
        }


        return res;


        
    }
};