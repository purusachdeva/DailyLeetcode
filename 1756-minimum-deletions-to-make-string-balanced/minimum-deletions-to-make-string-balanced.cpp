class Solution {
public:
    int minimumDeletions(string s) {

        vector<pair<int,int>> v(s.size(), {0, 0});

        for(int i = 1; i < s.size(); i++) {
            if (s[i-1] == 'b') v[i].second = v[i-1].second + 1;
            else v[i].second = v[i-1].second;
        }

        for(int i = s.size() - 2; i >= 0; i--) {
            if (s[i+1] == 'a') v[i].first = v[i+1].first + 1;
            else v[i].first = v[i+1].first;
        } 

        int mini = INT_MAX;
        for(auto i : v) {
            mini = min(i.first + i.second, mini);
        }

        return mini;
    }
};