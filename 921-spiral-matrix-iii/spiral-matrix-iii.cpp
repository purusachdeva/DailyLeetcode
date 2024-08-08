class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int n = rows*cols;
        int i = 1;
        int cCurr = cStart;
        int rCurr = rStart;

        vector<vector<int>> ans;
        int k = -1;
        while (ans.size() != rows*cols) {
            // right
            for(int j = 0; j < i; j++) {
                if (cCurr < cols && rCurr < rows && cCurr > -1 && rCurr > -1)  {
                    ans.push_back({rCurr, cCurr});
                }
                cCurr++;
            }

            if (k % 2 == 0) i++;
            k++;

            // down
            for(int j = 0; j < i; j++) {
                if (cCurr < cols && rCurr < rows && cCurr > -1 && rCurr > -1)  {
                    ans.push_back({rCurr, cCurr});
                }
                rCurr++;
            }

            if (k % 2 == 0) i++;
            k++;

            // left
            for(int j = 0; j < i; j++) {
                if (cCurr < cols && rCurr < rows && cCurr > -1 && rCurr > -1)  {
                    ans.push_back({rCurr, cCurr});
                }
                cCurr--;
            }

            if (k % 2 == 0) i++;
            k++;

            // up
            for(int j = 0; j < i; j++) {
                if (cCurr < cols && rCurr < rows && cCurr > -1 && rCurr > -1)  {
                    ans.push_back({rCurr, cCurr});
                }
                rCurr--;
            }

            if (k % 2 == 0) i++;
            k++;
        }

        return ans;
    }
};