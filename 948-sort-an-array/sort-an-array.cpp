class Solution {
public:

    void merge(vector<int>& nums, int i, int m, int j) {
        vector<int> merged(j - i + 1);
        int mergePointer = 0;
        int a = i, b = m + 1;

        while (a <= m && b <= j) {
            if (nums[a] <= nums[b]) {
                merged[mergePointer++] = nums[a++];
            } else {
                merged[mergePointer++] = nums[b++];
            }
        }

        while (a <= m) {
            merged[mergePointer++] = nums[a++];
        }
        while (b <= j) {
            merged[mergePointer++] = nums[b++];
        }

        int x = 0;
        for (a = i; a <= j; a++) {
            nums[a] = merged[x++];
        }
    }

    void mergeSort(vector<int>& nums, int i, int j) {
        if (i >= j) return;

        int m = (i + j) / 2;

        mergeSort(nums, i, m);
        mergeSort(nums, m + 1, j);

        merge(nums, i, m, j);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};