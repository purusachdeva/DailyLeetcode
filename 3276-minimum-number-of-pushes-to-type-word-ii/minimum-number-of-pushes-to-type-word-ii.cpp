class Solution {

    bool static sortByValue(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }

public:
    int minimumPushes(string word) {
        vector<int> mapping(26, -1);
        int ans = 0;
        int m = 0;

        vector<pair<int, int>> freq(26, {0, 0});
        for (auto ch : word) freq[ch - 'a'] = {freq[ch - 'a'].first + 1, ch - 'a'};
        sort(freq.begin(), freq.end(), [](pair<int,int> a, pair<int,int> b) {
            return a.first > b.first;
        });


        for (int i = 0; i < 26; i++) {
            if (freq[i].first == 0) {
                break;
            }

            int ch = freq[i].second;
            mapping[ch] = m;
            m++;
        }

        for (auto ch : word) {
            ans += mapping[ch - 'a']/8 + 1;
        }

        
        return ans;
    }
};