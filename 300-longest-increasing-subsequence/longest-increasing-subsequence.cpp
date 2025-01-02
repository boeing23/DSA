class Solution {
public:
    int solve(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            return 0; // Base case: no more elements
        }

        // Check if the subproblem is already solved
        if (dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }

        // Option 1: Skip the current element
        int nontake = solve(ind + 1, prev, nums, dp);

        // Option 2: Take the current element if valid
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + solve(ind + 1, ind, nums, dp);
        }

        // Store the result in the dp array
        return dp[ind][prev + 1] = max(nontake, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // Initialize DP table
        return solve(0, -1, nums, dp); // Start recursion
    }
};
