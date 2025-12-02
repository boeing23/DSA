class Solution {
public:
    string decodeString(string s) {

        vector<string>stack;

        for(char c:s)
        {
            if(c!=']')
            {
                stack.push_back(string(1,c));  //this converts single char c in string
            }
            else
            {
                string substr="";
                while(stack.back()!="[")
                {
                    substr=stack.back()+substr;
                    stack.pop_back();

                }
                stack.pop_back();    //pop '[';

                //now after opening there can be a digit so
                string k=""; // this stores the digit

                while(!stack.empty() && isdigit(stack.back()[0])) //isdigit(arg) take
                //char as an argument thus the stack.back()[0]) '[0]' is responsible 
                //for converting it to zero
                {
                    k=stack.back()+k;
                    stack.pop_back();
                    
                }

                int repeatedcount=stoi(k);
                string r="";


                for(int i=0;i<repeatedcount;i++)
                {
                    r+=substr;

                }
                stack.push_back(r);

            }

            



        }
        string res="";
            for(const string&part:stack)
            {
                res+=part;
            }

            return res;
        
    }
};