class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix.size() - 1;

        int rowIndex = -1;
        while (i <= j) {    
            int mid = (i + j) / 2;
            int lower = matrix[mid][0], upper = matrix[mid][matrix[0].size() - 1];

            if (target >= lower && target <= upper) {
                rowIndex = mid;
                break;
            } else if(target >= upper) i = mid + 1;
            else if(target <= lower) j = mid - 1;
        }

        int mid = (i + j) / 2;
        int lower = matrix[mid][0], upper = matrix[mid][matrix[0].size() - 1];
        if (target >= lower && target <= upper) rowIndex = mid;
        else return false;

        i = 0, j = matrix[0].size() - 1;

        while (i <= j) {
            mid = (i + j) / 2;
            int current = matrix[rowIndex][mid];
            if(target == current) return true;
            else if(target > current) i = mid + 1;
            else j = mid - 1;
        }

        mid = (i + j) / 2;
        if (matrix[rowIndex][mid] == target) return true;
        else return false;
    }
};