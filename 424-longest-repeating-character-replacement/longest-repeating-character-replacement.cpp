class Solution {
public:
    int characterReplacement(string s, int k) {

        int res=0;
        int l=0;
        int r=0;
        int maxf=0;

        vector<int>frq(26,0);

        for(int r=0;r<s.size();r++)
        {
            int idx=s[r]-'A';
            maxf=max(maxf,++frq[idx]);

            while((r-l)+1-maxf>k){
                --frq[s[l]-'A'];
                l++;
                
                
            }
            res=max((r-l)+1,res);
           

        
           
           



            



        }
        return res;
        
    }
};