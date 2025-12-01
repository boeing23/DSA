class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //so basically it needs to be solved using sliding window

        //so here the template of sliding window is

        int l=0;
        int res=0;
        unordered_set<char>seen;

    for(int r=0;r<s.size();r++)
    {
        char c=s[r];
        while(seen.count(c))
        {
            seen.erase(s[l]);
            l++;
        }

        seen.insert(c);
        res=max(res,r-l+1);

    }
    return res;

        
    }
};