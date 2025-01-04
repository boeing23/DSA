class Solution {
    #define pii pair<int,int>
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>left;
        unordered_map<char,int>right;
        unordered_set<string>res;
        

        for(char c: s)
        {
            right[c]++;

        }
        for(int m=0;m<s.length();m++)
        {
            right[s[m]]--;

            for(char c: left)
            {
                if(right[c]>0)
                {
                    string str = string(1, c) + string(1, s[m]);
                    res.insert(str);

                }
               
            }
             left.insert(s[m]);

        }
        return res.size();
    }
};