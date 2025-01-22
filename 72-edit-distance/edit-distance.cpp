class Solution {
public:
int solve(string &s1,string &s2, int i, int j,vector<vector<int>>&dp)
{
    if(i<0)
    {
        return j+1;
    }
    if(j<0)
    {
        return i+1;
    }
    if(s1[i]==s2[j])
    {
        return solve(s1,s2,i-1,j-1,dp);
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else
    {
        return dp[i][j]= 1 + min({solve(s1, s2, i - 1, j,dp), solve(s1, s2, i, j - 1,dp), solve(s1, s2, i - 1, j - 1,dp)});
    }
}
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));


        return solve(word1,word2,word1.size()-1,word2.size()-1,dp);
        
    }
};