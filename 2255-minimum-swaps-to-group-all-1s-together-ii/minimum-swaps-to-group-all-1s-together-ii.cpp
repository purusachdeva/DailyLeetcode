class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> copy = nums;
        int n = count(nums.begin(), nums.end(), 1);
        copy.insert(copy.end(), nums.begin(), nums.end());

        int i, j;
        int x = 0;
        int maxX = INT_MIN;
        for (j = 0; j < n; j++) {
            if (copy[j] == 1) x++;
        }

        i = 1;
        while (j < copy.size()) {
            if (copy[j] == 1) x++;
            if (copy[i-1] == 1) x--;

            i++;
            j++;
            maxX = max(x, maxX);
        }

        return n - maxX;
    }
};