class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>map(nums.begin(),nums.end());
        int res=0;

        for(const auto &i: map)
        {
            if(!map.count(i-1))
            {
                int len=1;
                while(map.count(len+i))
                {

                    len++;

                }

                res=max(len,res);
            }
        }

        return res;

        
    }
};