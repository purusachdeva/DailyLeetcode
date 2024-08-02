class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> copy = nums;
        int n = 0;
        for(auto i : nums) {
            if (i == 1) n++;
            copy.push_back(i);
        }

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