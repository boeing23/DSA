class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int sum0 = 0, maxScore = INT_MIN;
        vector<int> suffixSum(n, 0);

        // Build the suffix sum of ones
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + (s[i + 1] == '1' ? 1 : 0);
        }

        // Calculate the maximum score
        for (int i = 0; i < n - 1; ++i) {  // Stop at n-1 to avoid an empty right partition
            if (s[i] == '0') {
                sum0++;  // Increment the count of zeros in the left partition
            }
            int score = sum0 + suffixSum[i];
            maxScore = std::max(maxScore, score);
        }

        return maxScore;
    }
};
