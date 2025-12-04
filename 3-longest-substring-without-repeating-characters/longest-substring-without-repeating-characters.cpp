class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //so it is a sliding window question and to keep track of whether the window is valid or not we can use set

        //so first define the l and r

        int l=0;
        //then a variable to keep track of the max length
        int resLen=0;


        unordered_set<char>tracker;

        for(int r=0;r<s.size();r++)
        {
            char c=s[r];
            
        


            while(tracker.count(c))//this keeps the track of valid window
            {
                tracker.erase(s[l]);    //erasing because when the window moves the char is removed from left
                l++;



            } 
            tracker.insert(c);

            resLen=max(resLen,r-l+1);


        }


        return resLen;
        
    }
};