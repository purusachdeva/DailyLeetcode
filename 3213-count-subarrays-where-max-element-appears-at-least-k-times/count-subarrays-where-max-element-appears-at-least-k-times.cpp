class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_n = INT_MIN;
        for(auto i : nums) max_n = max(max_n, i);

        int cnt = 0, i = 0, j = 0;

        long long ans = 0;

        while(j < nums.size()) {
            if(nums[j] == max_n) cnt++;

            while((cnt > k) || (i <= j && cnt == k && nums[i] != max_n)) {
                if(nums[i] == max_n)
                    cnt -= 1;
                i++;
            }

            if(cnt == k) {
                ans += i + 1;
            }

            j++;
        }
        

        return ans;
    }
};