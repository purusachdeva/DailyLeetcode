/*

- find 3 * 3 Grid
- rowSum = colSum = diagSum
- Run through the grid with a sort of mask of 3*3

*/

class Solution {
    bool validMagicSquare(vector<vector<int>> square, int x, int y) {
        // Find the Magic Sum
        int sum = 0;
        for (int i = 0; i < 3; i++) sum += square[x + i][y];

        cout << "Magic Sum: " << sum;

        // Checking for row and column sum to be equal to the magic sum
        // And checking distinct elements from 1-9
        vector<int> freq(9, 0);

        for(int i = 0; i < 3; i++) {
            int tempRowSum = 0;
            int tempColSum = 0;
            for(int j = 0; j < 3; j++) {
                tempRowSum += square[x + i][y + j];
                tempColSum += square[x + j][y + i];
                
                if (square[x + i][y + j] < 1 || square[x + i][y + j] > 9 || square[x + j][y + i] < 1 || square[x + j][y + i] > 9 ) return false;

                // Checking distinct elements
                if (++freq[square[x + i][y + j] - 1] > 1) return false;
            }

            if (tempRowSum != sum || tempColSum != sum) return false;
        }

        // Checking for both of the diagonals' sum to be equal to the diagonal sum
        int diagonalSum1 = 0;
        int diagonalSum2 = 0;
        for(int i = 0; i < 3; i++) {
            diagonalSum1 += square[x + i][y + i];
            diagonalSum2 += square[x + i][y + 2 - i];
        } 

        cout << "\nDiagonal Sum: " << diagonalSum1 << ", " << diagonalSum2;

        if (diagonalSum1 != sum || diagonalSum2 != sum) return false;

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        int magicSquareCount = 0;
        for (int i = 0; i < rows - 2; i++) {
            for (int j = 0; j < cols - 2; j++) {
                if (validMagicSquare(grid, i, j))
                    magicSquareCount++;
            }
        }

        return magicSquareCount;
    }
};