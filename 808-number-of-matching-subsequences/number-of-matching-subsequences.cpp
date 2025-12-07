class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {


        //create a idxMap;

        unordered_map<char,vector<long long>>idxMap;

        for(int i=0;i<s.size();i++)
        {
            idxMap[s[i]].push_back(i);
        }


        int count=0;
        for(auto w: words)
        {
            //lastidx kuthe theu 
            long long lastIdx=-1;
            bool found=true;

            for(int i=0;i<w.size();i++)
            {
               long long newIdx=-1;

                if(idxMap.find(w[i])==idxMap.end())
                {
                    found=false;
                    break;
                }
                vector<long long>&indexList=idxMap[w[i]];
                auto it = upper_bound(indexList.begin(), indexList.end(), lastIdx);

                // If 'it' reached the end, no valid index was found
                if (it == indexList.end()) {
                    found = false;
                    break;
                }

                // Update lastIdx to the value found
                lastIdx = *it;

            }

            if(found)
            {
                count++;
            }
        }


        return count;

        
    }
};