class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        unordered_set<char>ch;
        
        int left=0;
        for(int r=0;r<s.size();r++)
        {
            while(ch.count(s[r]))
            {
                ch.erase(s[left]);
                left++;
                
            }
            ch.insert(s[r]);
            len=max(r-left+1,len);

        }

        return len;
    }
};