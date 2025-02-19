class Solution {
public:

//for genrating consider we will keep checking if the current string size is equal to n or not so therefore we need a current string, if size equals n then add it to the vector result.
void generate(int n,string curr, vector<string>&result)
{
    if(curr.length()==n)
    {
        result.push_back(curr);
        return;
    }
    //we keep on iterating through the list 

    for(char c: {'a','b','c'})
    {
        if(curr.empty()||curr.back()!=c)
        {
            generate(n,curr+c,result);
        }

    }
}
    string getHappyString(int n, int k) {
vector<string>result;

        generate(n,"",result);
        return k <= result.size() ? result[k - 1] : "";
        
    }
};