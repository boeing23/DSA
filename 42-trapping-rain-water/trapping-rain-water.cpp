class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int)height.size();
        if (n <= 2) return 0;

        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        long long water = 0; // use long long for safety on big arrays

        while (l < r) {
            if (height[l] <= height[r]) {
                leftMax = max(leftMax, height[l]);
                water += leftMax - height[l];
                ++l;
            } else {
                rightMax = max(rightMax, height[r]);
                water += rightMax - height[r];
                --r;
            }
        }
        return (int)water;
    }
};
