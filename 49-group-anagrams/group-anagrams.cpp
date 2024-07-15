class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(auto s : strs) {
            vector<int> count(26, 0);
            for(auto c : s) count[c - 'a']++;

            string key = "";
            for(auto i : count) key += (to_string(i) + ",");
            m[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto i : m) {
            ans.push_back(i.second);
        }

        return ans;
    }
};