class Solution {
public:
    int search(vector<int>& nums, int target) {
        int si = 0, ei = nums.size() - 1;

        while (si <= ei) {
            int mid = (si + ei) / 2;

            if (target == nums[mid]) return mid;
            if (target > nums[mid]) si = mid + 1;
            else ei = mid - 1;
        }

        int mid = (si + ei) / 2;
        if (target == nums[mid]) return mid;
        
        return -1;
    }
};