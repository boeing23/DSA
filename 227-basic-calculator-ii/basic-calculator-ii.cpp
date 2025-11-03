class Solution {
public:
    int calculate(string s) {
        
        char sign='+';
        int curr=0;
        stack<int>st;

        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                curr=curr*10+(s[i]-'0');

            }

            if((!isdigit(s[i]) && s[i] != ' ') || i == (int)s.size() - 1 )
            {
                if(sign=='+')
                {
                    st.push(curr);
                }
                else if(sign=='-')
                {
                    st.push(-curr);
                }
                else
                {
                    int a=st.top();
                    st.pop();
                    if(sign=='*')
                    {
                        st.push(a*curr);
                    }
                    else
                    {
                        st.push(a/curr);
                    }
                }

                sign=s[i];
                curr=0;
            }
        }
int sum=0;

        while(!st.empty())
        {
            sum+=st.top();
            st.pop();

        }

        return sum;
    }
};