class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, product = 1, count = 0;

        int n = nums.size();

        if(k <= 1) return 0;
        
        while(j < n) {
            product *= nums[j];

            while(product >= k) 
                product /= nums[i++];

            count += 1 + (j-i);
            j++;
        }

        return count;
    }
};