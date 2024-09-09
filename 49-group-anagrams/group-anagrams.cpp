class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (auto s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            m[sorted].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto i : m) {
            ans.push_back(i.second);
        }

        return ans;
    }
};