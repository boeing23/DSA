class Solution {
public:

void generate(string s, string &result, unordered_set<string> &existing, int ind,int n, bool &found)
{
    if(found) return;

    if(ind==n)
    {
        if(existing.find(s)==existing.end())
        {
            result=s;
            found=true;
        }
        return;
    }

    s[ind]='0';
    generate(s,result,existing,ind+1,n,found);

    s[ind]='1';
    generate(s,result,existing, ind+1,n,found);

    
    
}
    string findDifferentBinaryString(vector<string>& nums) {

        //get the size of each element.


        int numsl= nums[0].size();
        unordered_set<string> existing(nums.begin(), nums.end());
        string s(numsl, '0');
        string result;
        bool found=false;


       
        generate(s,result,existing,0,numsl,found);  
        return result;      
    }
};