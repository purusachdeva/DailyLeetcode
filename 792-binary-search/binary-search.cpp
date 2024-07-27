class Solution {
public:
    int search(vector<int>& nums, int target) {
        int si = 0, ei = nums.size() - 1;

        while(si <= ei) {
            int mid = (si + ei)/2;

            if(target == nums[mid]) return mid;
            else if(target > nums[mid]) si = mid + 1;
            else if(target < nums[mid]) ei = mid - 1;
        }
        
        return -1;
    }
};