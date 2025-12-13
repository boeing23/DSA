class Solution {
public:
    string longestPalindrome(string s) {

        int resLen=0;
        int resInd=0;

    for(int i=0;i<s.size();i++)
    {
        //for the odd len string you can use the logic of increasing from the middle.

        int start=i;
        int end=i;

        //odd length string


        while(start>=0 && end<s.size() && s[start]==s[end])
        {
            if(resLen<end-start+1)
            {
                resLen=end-start+1;
                resInd=start;
            }

            start--;
            end++;


        }
//even length string
        start=i;
        end=i+1;

        while(start>=0 && end<s.size() && s[start]==s[end])
        {
            if(resLen<end-start+1)
            {
                resLen=end-start+1;
                resInd=start;
            }

            start--;
            end++;


        }


    }

    return s.substr(resInd, resLen);
        
    }
};