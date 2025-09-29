class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>>map;
        vector<vector<string>>ans;
        

        for(string s:strs)
        {
            vector<int>frqmap(26,0);
            for(char c:s)
        {
            frqmap[c-'a']++;

            

        }

        string a=to_string(frqmap[0]);
        for(int i=1;i<26;i++)
        {
            a+=','+to_string(frqmap[i]);
        }

        map[a].push_back(s);



        }
for(const auto i:map)
    {
        ans.push_back(i.second);
    }
        return ans;
        
    }
};