class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans=strs[0];
        

    for(int i=0;i<strs.size();i++)
    {
        int j=0;
        

        string curr=strs[i];


        while(j<min(ans.length(),strs[i].size()))
        {
            if(ans[j]!=curr[j]) break;
            j++;
        }

        ans=ans.substr(0,j);
    }
        return ans;
    }
};