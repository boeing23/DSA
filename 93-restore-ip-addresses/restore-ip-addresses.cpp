
class Solution {
    vector<string>res;
public:
    vector<string> restoreIpAddresses(string s) {

        string path="";
        int step=0;

        dfs(s,0,step,path);

        return res;
        
    }

    void dfs(string &s, int start, int step, string path)
    {
        if (step == 4) {
            // Did we consume the entire string?
            if (start == s.length()) {
                path.pop_back(); // Remove the trailing '.'
                res.push_back(path);
            }
            return;
        }

        for(int i=start;i<start+3 && i < s.length();i++)    //i think here it would be a issue
        {
            string curr = s.substr(start, i - start + 1);
            if(curr[0]=='0' && curr.size()>1 ) break;
            
            
            if (stoi(curr) > 255) break;

            dfs(s,i+1,step+1,path+curr+'.');
            

        }
    }
};