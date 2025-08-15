class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;

        for(string &s : strs)
        {
            array<int,26> count={0};

            for(char c:s){
                count[c-'a']++;

            }

            string key;
            for(int n:count)
            {
                key+=to_string(n)+'#';
            }

            groups[key].push_back(s);

        }

        vector<vector<string>> results;

        for(auto &p: groups)
        {
            results.push_back(p.second);
        }

        return results;

    }
};