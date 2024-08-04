class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        vector<int> sumArray;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j] % 1000000007;
                sumArray.push_back(sum);
            }
        }

        sort(sumArray.begin(), sumArray.end());

        int sum = 0;
        for(int i = left - 1; i < right; i++) {
            sum += sumArray[i];
            sum = sum % 1000000007;
        }

        return sum;
    }
};