class Solution {
public:
    int reverse(int num) {
        int rev = 0;

        while(num != 0) {
            int temp = num%10;
            rev = rev*10 + temp;
            num/=10;
        }

        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        long long int nicePairs = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            nums[i] -= reverse(nums[i]);
        }

        map<int, int> mp;
        for(auto i : nums) {
            mp[i]++;
        }

        for(auto i : mp) {
            nicePairs += (long long)i.second*(i.second-1)/2;
            nicePairs;
        }

        return nicePairs%1000000007;
    }
};