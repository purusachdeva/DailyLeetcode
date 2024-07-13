class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> mp;
        for(auto i : nums) {
            if(mp[i]) return true;
            mp[i] = true;
        }

        return false;
    }
};