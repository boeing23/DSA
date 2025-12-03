class Solution {
public:
    int characterReplacement(string s, int k) {

        //this is the sliding window problem. until now we know that we have to keep track of maxF of that window
        //resLen


        int l=0;
        int maxF=INT_MIN;
       unordered_map<char,int>window;
       int resLen=0;

        for(int r=0;r<s.size();r++)
        {
            window[s[r]]++;
            if(maxF<window[s[r]])
            {
                maxF=window[s[r]];
            }
            

            while((r-l+1)-maxF > k)
            {
                

                window[s[l]]--;
                l++;
            }

            resLen=max(resLen, r-l+1);


        }
        return resLen;

        
        
    }
};