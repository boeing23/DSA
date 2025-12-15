class Solution {
    private:
    bool isVowel(char c)
    {
        char a=tolower(c);
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
        {
            return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {

        int l=0;
        int r=s.size()-1;
        while(l<r)
        {
            

           while(l<r && !isVowel(s[r])) r--;
           while(l<r && !isVowel(s[l])) l++;
           if(l<r)
            {
                swap(s[l],s[r]);
                l++;
                r--;
            }

        //    cout<<s<<endl;
        }
        return s;
    }
};