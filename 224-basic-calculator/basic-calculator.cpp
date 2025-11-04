class Solution {
public:
    int calculate(string s) {

        int sign=+1;
        int curr=0;
        int result=0;
        stack<int>st;

        for(char c: s)
        {
            if(isdigit(c))
            {
                curr=curr*10+(c-'0');

            }
            else if(c=='+')
            {
                result+=sign*curr;
                curr=0;
                sign=1;

            }
            else if(c=='-')
            {
                result+=sign*curr;
                curr=0;
                sign=-1;
            }

            else if(c=='(')
            {
                st.push(result);
                st.push(sign);
                curr=0;
                result=0;
                sign=1;

            }
            else if(c==')')
            {
                result+=curr*sign;
                int top=st.top();
                st.pop();
                result*=top;
             int a=st.top();
                st.pop();
                result+=a;
                sign=1;
                curr=0;

            }
        }
        result += (sign*curr); 
        return result;
        
    }
};