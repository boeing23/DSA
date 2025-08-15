class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>group;
        for(int x: nums)
        {
            group[x]++;
        }

        vector<vector<int>>bucket(nums.size()+1);

        for(auto &p:group)
        {
            bucket[p.second].push_back(p.first);
        }
vector<int>res;
        for(int i=nums.size();i>=1 && res.size() < k;i--)
        {
            for(auto &p:bucket[i])
            {
                res.push_back(p);
                if(res.size()>k) break;

            }
        }
return res;






    }
};