class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum=0; // this is for prefix sum
        int count[2]={1,0};   //it keeps the check for number of odd or even sums. the count[0] is set to 1 becuase when we start with 0 the even sum is always 1;
       int result=0; //this is the final result
       int MOD = 1000000007;


        


        for(int i=0;i<arr.size();i++)
        {
            sum=sum+arr[i];
            int parity=sum%2;

            if (parity < 0) parity += 2;
            result=(result+count[1-parity])%MOD;

            count[parity]++;


        }

        return result;
        
    }
};