class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];

        for(int i=1;i<strs.size();i++)
        {
            string cW=strs[i];
            if(cW.empty()) return "";
            int l=0;
            for(int i=0;i<cW.size();i++)
            {
                while(l<min(ans.length(),cW.length()))
                {
                    if(ans[l]==cW[l])
                    {
                        l++;
                    }
                    else
                    {
                        break;
                    }
                }
                ans=cW.substr(0,l);
            }
        }

        return ans;
    }
};