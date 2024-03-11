class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp;
        int i = 1;
        for(auto ch : order) {
            mp[ch] = i++;
        }

        vector<char> vec(26, 0);
        map<char,int> freq; 

        string ans = "";
        for(auto ch : s) {
            freq[ch]++;
            if(mp[ch] > 0) vec[mp[ch]] = ch;
            else ans += ch;
        }

        for(int a = 0; a < vec.size(); a++) {
            if(mp[vec[a]] > 0) {
                while(freq[vec[a]] != 0) {
                    ans += vec[a];
                    freq[vec[a]]--;
                }
            }
        }

        return ans;
    }

};