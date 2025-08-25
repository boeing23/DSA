class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        sort(piles.begin(),piles.end());
        


        int k=piles[piles.size()-1];

        int l=1;
        int r=k;
        int res=r;

        while(l<=r)
        {
            int mid=(l+r)/2;
            long long time=0;

            for(int p : piles)
            {
                time+=ceil(static_cast<double>(p)/mid);
            }

            if(time<=h) 
            {
                res=mid;

                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
            

        }
        return res;


    }
};