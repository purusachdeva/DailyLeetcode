class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for (auto i : chalk) sum += i;

        k = k % sum;

        int i = 0;
        while (1) {
            if (chalk[i] > k) return i;
            else k -= chalk[i];

            i++;
        }

        return 0;
    }
};