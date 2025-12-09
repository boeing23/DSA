class Solution {
    vector<vector<int>>res;
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int>sub;


        dfs(k,n,1,sub);

        return res;
        
    }

    void dfs(int k, int n, int start, vector<int>sub)
    {
        if(k==0 && n==0)
        {
            res.push_back(sub);
            return;
        }

        if(k==0 || n<=0) return;

        for(int end=start;end<=9;end++)
        {
            if(end>n) return;

            sub.push_back(end);
            dfs(k-1,n-end, end+1, sub);
            sub.pop_back();
        }
    }
};