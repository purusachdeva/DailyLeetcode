class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> present;

        for (auto i : allowed) present[i] = true;
        int count = words.size();
        
        for (auto word : words) {
            for (auto j : word) {
                if (present[j] == false) {
                    count--;
                    break;
                }
            }
        }

        return count;
    }
};