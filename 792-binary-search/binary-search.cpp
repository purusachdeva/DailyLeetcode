class Solution {
public:
    int helper(vector<int>& nums, int target, int i, int j) {
        if(i > j || (i == j && target != nums[i])) return -1;

        int mid = (i + j)/2;
        if(target == nums[mid]) return mid;

        if(target > nums[mid]) return helper(nums, target, mid + 1, j);

        return helper(nums, target, i, mid - 1);
    }

    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;

        return helper(nums, target, i, j);
    }
};