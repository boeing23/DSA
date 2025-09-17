class Solution {
    vector<vector<string>>res;

public:
    vector<vector<string>> partition(string s) {

        vector<string>sub;

        dfs(sub,s,0);
        return res;

    
        
    }
    bool isPal(int l, int r, string s)
       {
        while(l<r)
        {
            if(s[l++]!=s[r--]) return false;
        }

        return true;
       }

    void dfs(vector<string>&sub, string s, int start)
    {
        int n = (int)s.size();
        if (start >= n) {                 // base: consumed entire string
            res.push_back(sub);
            return;
        }

       for(int end=start;end<s.size();end++)
       {
        if(isPal(start,end,s))
        {
            sub.push_back(s.substr(start,end-start+1));
            dfs(sub, s, end+1);
            sub.pop_back();
        }
       }


       
    }
};