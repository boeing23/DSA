class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char>st;

        int l=0;
        // int r=s.size()-1;
        int maxL=0;

        for(int i=0;i<s.size();i++)
        {
            while(st.count(s[i]))
            {
                st.erase(s[l]);
                l++;
            }

            maxL=max(i-l+1,maxL);

            st.insert(s[i]);
        }

        return maxL;
        
    }
};