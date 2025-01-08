class Solution {
public:

bool isprefix(const string &a,const string &b)
{
    int n=a.size();
    int m=b.size();
    if(n>m)
    {
        return false;
    }
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]!=b[i])
        {
            return false;
        }
    }
    return true;

}
bool issuffix(const string &a,const string &b)
{
    int n=a.size();
    int m=b.size();
    if(n>m)
    {
        return false;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]!=b[m-(n-i)])
        {
            return false;
        }
    }
    return true;

}
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(issuffix(words[i],words[j]) && isprefix(words[i],words[j]))
                {
                    count++;
                }
            }

        }
        return count;
        
    }
};