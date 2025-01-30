class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if (n <= 1) return 1;

        int count = 0;

        auto expand_from_center = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
                count++;
            }
        };

        for(int i = 0; i < n; i++) {
            expand_from_center(i, i);
            expand_from_center(i, i + 1);
        }

        return count;
    }
};