class Solution {
public:
    bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

    int maximumPrimeDifference(vector<int>& nums) {
        int left = -1, right = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(isPrime(nums[i])) {
                if(left == -1) {
                    left = i;
                    right = i;
                }

                else right = i;
            }
        }

        return right - left;
    }
};