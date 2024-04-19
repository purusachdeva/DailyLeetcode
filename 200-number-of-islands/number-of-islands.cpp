class Solution {
    void explore(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] != '1')
            return;

        visited[i][j] = true;

        explore(grid, visited, i+1, j);
        explore(grid, visited, i-1, j);
        explore(grid, visited, i, j+1);
        explore(grid, visited, i, j-1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;

        int count = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    explore(grid, visited, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};