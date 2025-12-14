class Solution {
public:
    string decodeString(string s) {

        stack<string>st;

        for(int i=0;i<s.length();i++)
        {
            char curr=s[i];
            if(curr!=']')
            {
                st.push(string(1,curr));
            }
            else
            {
                string sub="";
                while(!st.empty()&&st.top()!="[")
                {
                    sub=st.top()+sub;
                    st.pop();
                    
                }

                st.pop();
                string k="";
                while(!st.empty() && isdigit(st.top()[0]))
                {
                    k=st.top()+k;
                    st.pop();
                }
                int repeated=stoi(k);
                string rep="";

                for(int i=0;i<repeated;i++)
                {
                    rep+=sub;

                }

                st.push(rep);
            }
            
        }

        string res="";

        while(!st.empty())
        {
            res=st.top()+res;
            st.pop();
        }

        return res;
        
    }
};