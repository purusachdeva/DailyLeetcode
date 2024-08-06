class Solution {

    bool static sortByValue(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }

public:
    int minimumPushes(string word) {
        vector<int> mapping(26, -1);
        int ans = 0;
        int i = 0;

        map<char, int> freq;
        for (auto ch : word) {
            freq[ch]++;
        }

        vector<pair<char, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), sortByValue);

        for (auto ch : freqVec) {
            if (mapping[ch.first - 'a'] == -1) {
                mapping[ch.first - 'a'] = i; 
                i++;
            }
        }

        for (auto ch : word) {
            ans += mapping[ch - 'a']/8 + 1;
        }

        
        return ans;
    }
};