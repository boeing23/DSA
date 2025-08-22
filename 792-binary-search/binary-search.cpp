class Solution {
public:
    int search(vector<int>& nums, int target) {

        int s=0;
        int end=nums.size()-1;
        while(s<=end)
        {
            int mid=(s+end)/2;

           if(nums[mid]==target) return mid;
           else if(nums[mid]>target) end=mid-1;
           else s=mid+1;
        }

        return -1;
        
    }
};