class Solution {
public:

    int maxScoreSightseeingPair(vector<int>& values) {
        int sum=INT_MIN;
        int a=values[0];
       int b;
             for(int j=1;j<values.size();j++)
             {
                b=values[j]-j;
                sum=max(sum,a+b);
                a=max(a,values[j]+j);
             }

        
        return sum;
        
    }
};