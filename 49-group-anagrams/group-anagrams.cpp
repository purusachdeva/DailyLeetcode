class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(auto s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            groups[sortedStr].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto group : groups)
            ans.push_back(group.second);

        return ans;
    }
};