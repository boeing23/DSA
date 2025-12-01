class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int rem=sum%p;

        if(rem==0) return 0;


        vector<int>pref(nums.size()+1,0);
        

        for(int i=0;i<nums.size();i++)
        {
            pref[i+1]=(nums[i]+pref[i])%p;  // this will create prefix table

        }

        unordered_map<int,int>map;
        map[0]=0;
        int ans=(int)nums.size();
        for(int j=1;j<=nums.size();j++)
        {
            int target=(pref[j]-rem+p)%p;           //this tells us prefix sum which you might have encountered between the jth pos and ith pos
            if(map.count(target))
            {
                ans=min(ans,j-map[target]);
            }

            map[pref[j]]=j;
            

        }

        return ans==(int)nums.size() ? -1 : ans;



        


        
    }
};