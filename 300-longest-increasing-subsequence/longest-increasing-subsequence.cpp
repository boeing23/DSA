class Solution {
    vector<vector<int>> dp; // dp[i][prev+1]
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        dp.assign(n, vector<int>(n + 1, -1)); // prev in [-1..n-1] -> [0..n]
        return dfs(nums, 0, -1);
    }

private:
    int dfs(const vector<int>& nums, int i, int prev) {
        if (i == (int)nums.size()) return 0;

        int &memo = dp[i][prev + 1];
        if (memo != -1) return memo;

        // Skip current
        int best = dfs(nums, i + 1, prev);

        // Take current if it increases
        if (prev == -1 || nums[i] > nums[prev]) {
            best = max(best, 1 + dfs(nums, i + 1, i));
        }

        return memo = best;
    }
};
