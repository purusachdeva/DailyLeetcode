class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int i, int j) {

        while (i <= j) {
            int mid = (i + j) / 2;

            if (nums[mid] == target) return mid;
            if (nums[mid] < target) i = mid + 1;

            else j = mid - 1;
        }

        int mid = (i + j) / 2;
        if (nums[mid] == target) return mid;

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;

        // if (nums[i] == target) return i;
        // if (nums[j] == target) return j;

        while (i <= j) {

            if (nums[i] == target) return i;
            if (nums[j] == target) return j;

            int m = (i + j) / 2;
            if(target == nums[m]) return m;

            if (target > nums[j] && target > nums[i]) {
                i++;
                j--;
            }

            else if (target > nums[j] && target < nums[i]) {
                return -1;
            }

            else if (target < nums[j] && target > nums[i]) {
                return binarySearch(nums, target, i, j);
            }

            else if (target < nums[j] && target < nums[i]) {
                i++;
                j--;
            }
        }

        return -1;
    }
};