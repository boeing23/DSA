class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(s.length() + 1, 0);

        // Step 1: Apply the range updates to the diff array
        for (int i = 0; i < shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if (direction == 1) {
                diff[start] += 1;
                diff[end + 1] -= 1;
            } else {
                diff[start] -= 1;
                diff[end + 1] += 1;
            }
        }

        // Step 2: Accumulate the difference array to get the net shifts
        for (int i = 1; i <= n; ++i) {
            diff[i] += diff[i - 1];
        }

        // Step 3: Apply the shifts to the string and form the result
        string res;
        for (int i = 0; i < n; ++i) {
            int count = diff[i] % 26;
            if (count < 0)
                count = 26 + count; // Ensure non-negative shift

            char curr = char((s[i] - 'a' + count) % 26 + 97);
            res.push_back(curr);
        }

        return res;
    }
};
