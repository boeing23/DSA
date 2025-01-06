class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        int sum=0;
        int right=0;
        for(int i=0;i<n;i++)
        {
            if(boxes[i]=='1')
            {
                sum+=i;
                right++;
            }

        }
        vector<int>ans(n,0);
        int left=0;
        int prefix=0;

        for(int i=0;i<n;i++)
        {
            int moves = sum + prefix;
            ans[i]=moves;

            if(boxes[i]=='1')
            {
                left++;
                right--;
            }
            prefix += left;
            sum -= right;


        }
        return ans;
        
    }
};