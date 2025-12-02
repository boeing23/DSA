class Solution {
public:
    string decodeString(string s) {
vector<string>stack;


        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(c!=']')
            {
                stack.push_back(string(1,c));
            }
            else
            {
                //for example [bc

                string substr="";
                while(stack.back()!="[")
                {
                    substr=stack.back()+substr;
                    stack.pop_back();
                }

                stack.pop_back(); //removes '[' 

                string k="";
                while(!stack.empty() && isdigit(stack.back()[0]))
                {
                    k=stack.back()+k;
                    stack.pop_back();

                }


                int repeated= stoi(k);
                string r="";
                for(int i=0; i<repeated; i++)
                {
                    r+=substr;

                }

                stack.push_back(r);

            }
        }
string res="";
        for(const auto&part: stack)
        {
            res+=part;

        }

        return res;
        
    }
};