class Solution {
public:
    string decodeString(string s) {
        stack<string>st;

        for(char c: s)
        {
            if(c!=']')
            {
                st.push(string(1,c));
            }
            else
            {
                string substr="";
                while(!st.empty() && st.top()!="[")
                {
                    substr=st.top()+substr;
                    st.pop();
                }
                st.pop();
                string k="";

                while(!st.empty() && isdigit(st.top()[0]))
                {
                    k=st.top()+k;
                    st.pop();
                }
                int repeat=stoi(k);
                string rep="";
                for(int i=0;i<repeat;i++)
                {
                    rep+=substr;
                }
                st.push(rep);
            }
        }

        string ans="";

        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }

        return ans;
    }
};