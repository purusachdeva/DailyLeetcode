class Solution {
    bool static compare(int& a, int& b) {
        string x = to_string(a);
        string y = to_string(b);

        if ((x + y) > (y + x)) return true;
        return false;
    }

public:
    string largestNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(), nums.end(), compare);

        for (auto i : nums)
            ans += to_string(i);

        if (ans[0] == '0') return "0";

        int j = 0;
        if (ans[0] == '0') j++;


        return ans.substr(j);
    }
};