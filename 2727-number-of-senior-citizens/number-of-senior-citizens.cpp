class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto i : details) {
            if (stoi(i.substr(11, 2)) > 60) ans++;
        }

        return ans;
    }
};