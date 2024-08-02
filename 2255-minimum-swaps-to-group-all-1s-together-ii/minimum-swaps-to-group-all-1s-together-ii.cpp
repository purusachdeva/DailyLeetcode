class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = count(nums.begin(), nums.end(), 1);
        if (n == 0) return 0;

        int i, j;
        int x = 0;
        int maxX = INT_MIN;
        for (j = 0; j < n; j++) {
            if (nums[j] == 1) x++;
        }

        i = 1;
        while (j < 2*nums.size()) {
            if (nums[j%nums.size()] == 1) x++;
            if (nums[(i-1)%nums.size()] == 1) x--;

            i++;
            j++;
            maxX = max(x, maxX);
        }

        return n - maxX;
    }
};