class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        if (n <= 1) return s;

        auto expand_from_center = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            return s.substr(left + 1, right - left - 1);
        };

        string maxStr = s.substr(0, 1);

        for (int i = 0; i < n; i++) {
            string odd = expand_from_center(i, i);
            string even = expand_from_center(i, i + 1);

            if (odd.length() > maxStr.length())
                maxStr = odd;

            if (even.length() > maxStr.length())
                maxStr = even;
        }

        return maxStr;
    }
};