class Solution {
    vector<vector<string>>res;
public:
    vector<vector<string>> partition(string s) {

vector<string>path;
        

        dfs(s,0,path);

        return res;

        

        
    }
bool isPalindrome(string curr)
{
    int l=0;
    int r=curr.size()-1;

    while(l<=r)
    {
        if(curr[l]!=curr[r])
        {
            return false;
        }
        r--;
        l++;
    }

    return true;
}
    void dfs(string &s, int start, vector<string>path)
    {
        if(start==s.length())
        {
            res.push_back(path);

            return;

        }

        for(int i=start;i<s.length();i++)
        {
            string curr=s.substr(start,i-start+1);
            if(isPalindrome(curr))
            {
                path.push_back(curr);
                dfs(s,i+1,path);

                path.pop_back();
            }
        }
    }
};