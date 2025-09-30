class Solution {
public:
    string longestPalindrome(string s) {
        //the logic is to expand on the sides until you find hit the bottleneck;


        int res=0;
        int resIn=0;

        for(int i=0;i<s.size();i++)
        {
            int l=i;
            int r=i;

            while(l>=0 && r<s.size()&& s[l]==s[r])
            {
                if(res<r-l+1)
                {
                    resIn=l;
                    res=r-l+1;

                }
                
                l--;
                r++;
                
            }
            l=i;
            r=i+1;
            while(l>=0 && r<s.size()&& s[l]==s[r])
            {
                if(res<r-l+1)
                {
                    resIn=l;
                    res=r-l+1;

                }
                l--;
                r++;
                
            }

        }

        return s.substr(resIn,res);
    
    }
};