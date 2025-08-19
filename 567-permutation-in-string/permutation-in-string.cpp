class Solution {
public:
    bool checkInclusion(string s1, string s2) {

if (s1.size() > s2.size()) return false;
        int s1count[26]={0};
        int s2count[26]={0};

        for(int i=0;i<s1.size();i++){
            s1count[s1[i]-'a']++;
            s2count[s2[i]-'a']++;


        }

        int matches=0;

        for(int i=0;i<26;i++)
        {
            if(s1count[i]==s2count[i]) matches++;
        }




        int l=0;
        for(int r=s1.length();r<s2.length();r++)
        {
            if(matches==26) return true;

            int idx=s2[r]-'a';
            s2count[idx]++;

            if(s1count[idx]==s2count[idx]) matches++;
            else if (s1count[idx] + 1 == s2count[idx]) {
                matches--;
            }
            idx=s2[l]-'a';
            s2count[idx]--;
            if(s1count[idx]==s2count[idx]) matches++;
            else if (s1count[idx] - 1 == s2count[idx]) {
                matches--;
            }

            l++;
        }


        return matches==26;


        
    }
};