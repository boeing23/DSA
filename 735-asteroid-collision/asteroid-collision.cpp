class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++)
        {
            bool destroyed=false;
            while(!st.empty() && st.top()>0 &&asteroids[i]<0)
            {
                if(abs(st.top())<abs(asteroids[i]))
                {
                    st.pop();
                    continue;
                }
                else if(abs(st.top())==abs(asteroids[i]))
                {
                    st.pop();
                    destroyed=true;
                    break;
                }
                else { 
                    // abs(st.top()) > abs(cur): current asteroid destroyed
                    destroyed = true;
                    break;
                }

                
            }
            if(!destroyed) st.push(asteroids[i]);

            
            
            

            
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());  // 🔥 important

        return ans;
    }
};