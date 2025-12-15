class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxP=0;

        for(int i=0;i<piles.size();i++)
        {
            maxP=max(maxP,piles[i]);
        }

        int l=1;
        int r=maxP;
        int res=0;

        while(l<=r)
        {
          long long totalT=0;
            int mid=l+(r-l)/2;
            for(int i=0;i<piles.size();i++)
            {
               totalT+=ceil(static_cast<double>(piles[i])/mid);

            }

            if(totalT<=h)
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