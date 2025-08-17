class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>unique(nums.begin(),nums.end());
        int best=0;
        for(auto x:unique)
        {
            if(!unique.count(x-1))
            {
                int curr=x;
                int len=1;

                while(unique.count(curr+1)){
                    curr++;
                    len++;
                }
                if(len>best) best=len;
            }

        }
        return best;
    }
};