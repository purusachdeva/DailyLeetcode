class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        
        for(auto i : nums) {
            mp[i]++;
        }

        int ans = 0;

        for(auto i : mp) {
            if(i.second > nums.size() / 2) ans = i.first;
        }

        return ans;
    }

};