class Solution {
public:
vector<int>convert(string s,vector<int>&v)
{
    string part;
    stringstream ss(s);
    
    while(getline(ss,part,'.'))
    {
        v.push_back(stoi(part));
    }
    return v;
}
    int compareVersion(string version1, string version2) {
        
        vector<int>v1;
        vector<int>v2;
        string part;

       convert(version1,v1);
       convert(version2,v2);

       int n=(int)max(v1.size(),v2.size());


      for(int i=0;i<n;i++)
      {
        int a=(i<v1.size() ? v1[i] : 0);
        int b=(i<v2.size() ? v2[i] : 0);

        if(a<b) return -1;
        if(a>b) return 1;
      }

      return 0;

        
    }


};