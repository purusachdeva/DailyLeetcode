class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto i : nums) set.insert(i);

        int maxLen = 0;
        for(auto i : nums) {
            if(set.find(i - 1) == set.end()) {
                int len = 1;
                int j = i;
                while(set.find(j + 1) != set.end()) {
                    len++;
                    j++;
                }

                maxLen = max(len, maxLen);
            }
        }

        return maxLen;
    }
};