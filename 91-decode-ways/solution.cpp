class Solution {
public:

    int helper(string& s, int index, vector<int>& dp) {
        if (index == s.length()) return 1;
        if (s[index] == '0') return 0;
        if (dp[index] != -1) return dp[index];

        int total = helper(s, index + 1, dp);

        if (index + 1 < s.length() && 
            (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))) {
                total += helper(s, index + 2, dp);
        }

        dp[index] = total;

        return total;
    }

    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> dp(s.length(), -1);
        return helper(s, 0, dp);
    }
};