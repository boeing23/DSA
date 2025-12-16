class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int maxP=0;
        for(int r=0;r<prices.size();r++)
        {
            if(prices[r]<prices[l])
            {
                l=r;
            }
            else
            {
                maxP=max(maxP, prices[r]-prices[l]);

            }

            
        }

        return maxP;
    }
};