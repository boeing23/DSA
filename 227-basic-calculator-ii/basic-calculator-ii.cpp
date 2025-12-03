class Solution {
public:
    int calculate(string s) {

        int op='+';
        int number=0;
        stack<int>st;

        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(isdigit(c))
            {
                number=number*10 + (c-'0');
            }
            if(!isdigit(c) &&c!=' ' || i==s.size()-1)
            {
                if(op=='+')
                {
                    st.push(number);
                }
                else if(op=='-')
                {
                    st.push(-number);
                }
                else if(op=='*')
                {
                    int a =st.top();
                    st.pop();
                    st.push(a*number);

                }
                else if(op=='/')
                {
                    int a =st.top();
                    st.pop();
                    st.push(a/number);

                }

                op=c;
                number=0;


            }
        }
        int res=0;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }

        return res;

        
    }
};