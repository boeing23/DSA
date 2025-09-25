class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int>counts;
        map<string,int>subdomains;

        for(auto &entry:cpdomains){

            int spacePos=entry.find(' ');
            int count=stoi(entry.substr(0,spacePos));
            string domain=entry.substr(spacePos+1);

            for(int i=0;i<domain.size();i++)
            {
               if(i == 0 || domain[i] == '.') {
                    string subdomain = domain.substr(i == 0 ? 0 : i + 1); 
                    counts[subdomain] += count;                            
                }

            }

        }

        vector<string>result;
        for(auto&[subD, frq]:counts)
        {
            result.push_back(to_string(frq)+" "+subD);
        }

        return result;
        
    }
};