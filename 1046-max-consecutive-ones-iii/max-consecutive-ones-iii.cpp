class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, res = 0, numszero = 0;

        for (int r = 0; r < (int)nums.size(); ++r) {
            if (nums[r] == 0) ++numszero;

            while (numszero > k) {
                if (nums[l] == 0) --numszero;  // shrink and update zero count
                ++l;
            }

            res = std::max(res, r - l + 1);   // window [l..r] has ≤ k zeros
        }

        return res;
    }
};
