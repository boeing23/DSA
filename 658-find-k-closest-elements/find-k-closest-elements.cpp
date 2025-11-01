class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int r=arr.size()-1;
        int l=0;


        while(r-l>=k)
        {
            if(abs(x-arr[l])<=abs(x-arr[r]))
            {
                r--;
            }
            else
            {
                l++;
            }

        }

        return vector<int>(arr.begin()+l,arr.begin() + r + 1);
        
    }
};