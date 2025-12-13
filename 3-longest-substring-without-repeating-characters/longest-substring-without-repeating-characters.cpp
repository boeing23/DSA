class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //it's a sliding window problem

        // we have to maintain a window in this

        // and a variable which stores the maxlength of that widnow

        int left=0;
        int maxL=0;

        unordered_set<char>st; //this will keep track of unique chars in the window;

        for(int r=0;r<s.size();r++)
        {
            char c=s[r];



            while(st.count(c))
            {
                st.erase(s[left]);
                left++;
                
            }

            maxL=max(maxL,r-left+1);
            st.insert(s[r]);


        }
return maxL;
        
    }
};