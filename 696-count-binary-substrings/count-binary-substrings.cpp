class Solution {
public:
    int countBinarySubstrings(string s) {

        int currCon=1;
        int prevCon=0;
        int ans=0;

        for(int i=1;i<s.size();i++)
        {
            if(s[i]!=s[i-1])
            {
                ans+=min(prevCon,currCon);

                prevCon=currCon;
                currCon=1;

            }
            else
            {
                 currCon++;
            }
        }

        ans+=min(currCon, prevCon);

        return ans;
        
    }
};