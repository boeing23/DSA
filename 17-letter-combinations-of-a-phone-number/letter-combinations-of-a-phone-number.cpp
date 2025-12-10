class Solution {
    vector<string>res;
    vector<string>mapping={" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {

        //everytime decalre a path
        string path="";

        dfs(digits,0,path);
        return res;



        
    }

    void dfs(string digits, int index, string path)
    {
        if(index==digits.length())
        {
            res.push_back(path);
            return;
        }

        int digit=digits[index]-'0';
        string letters=mapping[digit];

        for(char letter: letters)
        {
            
            dfs(digits,index+1,path+letter);
        }
    }
};