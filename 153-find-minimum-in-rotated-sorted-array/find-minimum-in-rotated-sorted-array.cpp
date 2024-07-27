class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            int m = (i + j) / 2;

            if (nums[i] < nums[j]) return nums[i];

            if (nums[i] <= nums[m]) {
                i = m + 1;
            } else j = m;
        }

        return nums[i];
    }
};