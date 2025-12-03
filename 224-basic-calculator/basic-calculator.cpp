class Solution {
public:
    int calculate(string s) {
        int number=0;
        int result=0;
        int sign=1;
        stack<int>st;
        for(char c: s)
        {
            if(isdigit(c))
            {
                number=number*10 + (c-'0');
            }
            else if(c=='+')
            {
                result+=sign*number;
                number=0;
                sign=+1;
                
            }
            else if(c=='-')
            {
                result+=sign*number;
                sign=-1;
                number=0;


            }
            else if(c=='(')
            {
                st.push(result);
                st.push(sign);

                number=0;
                result=0;
                sign=1;

            }
            else if(c==')')
            {
                result+=sign*number;
                int outersign=st.top();
                st.pop();
                result*=outersign;
                int outernumber=st.top();
                st.pop();

                result+=outernumber;
                number=0;
                sign=1;
            }
        }

        result+=sign*number;
        return result;
    }
};