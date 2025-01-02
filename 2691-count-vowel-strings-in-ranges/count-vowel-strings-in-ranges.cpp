class Solution {
public:
bool isVowel(char ch) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    return vowels.count(tolower(ch)) > 0;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // To store cumulative frequency of words starting and ending with vowels

     // Cumulative count of valid words

    vector<int> freq(words.size(), 0);
    int count = 0;

    for (int i = 0; i < words.size(); i++) {
        if (!words[i].empty() && isVowel(words[i].front()) && isVowel(words[i].back())) {
            count++;
        }
        freq[i] = count; // Store the cumulative count
    }

    vector<int> results;
    for (const auto& query : queries) {
        int l = query[0];
        int r = query[1];

        int result = freq[r] - (l > 0 ? freq[l - 1] : 0);
        results.push_back(result);
    }

    return results;
        
    }
};