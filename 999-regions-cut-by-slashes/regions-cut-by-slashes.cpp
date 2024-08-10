/*

We convert this problem to a textbook number of islands problem


*/

class Solution {
    void explore(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] != 0)
            return;

        visited[i][j] = true;
        explore(grid, visited, i + 1, j);
        explore(grid, visited, i - 1, j);
        explore(grid, visited, i, j + 1);
        explore(grid, visited, i, j - 1);
    }

    int numIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int count = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    explore(grid, visited, i, j);
                    count++;
                }
            }
        }

        return count;
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int newRows = rows * 3, newCols = cols * 3;
        vector<vector<int>> newGrid(newRows, vector<int>(newCols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '/') {
                    int x = i * 3, y = j * 3;

                    for (int k = 0; k < 3; k++) 
                        newGrid[x + 2 - k][y + k] = 1;
                }

                if (grid[i][j] == '\\') {
                    int x = i * 3, y = j * 3;

                    for (int k = 0; k < 3; k++) 
                        newGrid[x + k][y + k] = 1;
                }
            }
        }

        // now check number of islands
        return numIslands(newGrid);

        return 0;
    }
};