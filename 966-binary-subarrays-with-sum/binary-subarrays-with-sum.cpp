class Solution {
public:
    int atMostn(vector<int>& nums, int n) {
        int i = 0, sum = 0, result = 0;

        for(int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while(sum > n && i <= j) {
                sum -= nums[i];
                i++;
            }

            // Counting every possible array ending with index j and starting with i
            result += j - i + 1; 
        }

        return result;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // common subarrays get cancelled
        return atMostn(nums, goal) - atMostn(nums, goal-1);
    }
};