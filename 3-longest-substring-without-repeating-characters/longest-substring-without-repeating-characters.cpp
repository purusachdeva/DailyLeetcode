class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;

        unordered_map<char, int> index;
        int maxi = 0;

        while (i <= j && j < s.length()) {
            if (index.count(s[j]) > 0 && index[s[j]] >= i) {
                i = index[s[j]] + 1;
            }

            maxi = max(j - i + 1, maxi);

            index[s[j]] = j;

            j++;
        }

        return maxi;
    }
};