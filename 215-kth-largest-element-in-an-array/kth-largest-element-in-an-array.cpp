class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int>maxHeap;

        for(int i=0;i<nums.size();i++)
        {
            maxHeap.push(nums[i]);
            
        }

        int count=k-1;
        while(count>0)
        {
            maxHeap.pop();
            count--;
        }

        return maxHeap.top();
        
    }
};