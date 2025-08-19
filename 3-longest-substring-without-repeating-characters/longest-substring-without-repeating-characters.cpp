class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int best=0;
        unordered_map<char,int>seen;

        int left=0;

        for(int r=0;r<s.size();r++)
        {
            char c=s[r];
            if(seen.count(c) && seen[c]>=left) left=seen[c]+1;

            seen[c]=r;
            best=max(best,r-left+1);
        }
        
return best;
    
        
    }
};