class Solution {
public:
    int getLucky(string s, int k) {
        string ans = "";

        // convert
        for (auto i : s) ans += to_string(i - 'a' + 1);

        int curr;

        // transformation
        while (k--) {
            curr = 0;
            for (auto i : ans) curr += (i - '0');
            ans = to_string(curr);
        }

        return curr;
    }
};