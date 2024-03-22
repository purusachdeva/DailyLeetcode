class Solution {
public:
    bool checkCycle(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, char val, int cameFrom) {

        if(i >= grid.size() || j >= grid[0].size()) return false;

        if(grid[i][j] != val) {
            if(val == '$')
                val = grid[i][j];
            
            else
                return false;
        }

        if(visited[i][j]) {
            return true;
        }

        visited[i][j] = true;

        bool a = false, b = false, c = false, d = false;
        
        if(cameFrom != 3) a = checkCycle(grid, visited, i + 1, j, val, 1);
        if(a) return true;
        if(cameFrom != 4) b = checkCycle(grid, visited, i, j+1, val, 2);
        if(b) return true;
        if(cameFrom != 1) c = checkCycle(grid, visited, i - 1, j, val, 3);
        if(c) return true;
        if(cameFrom != 2) d = checkCycle(grid, visited, i , j - 1, val, 4);
        if(d) return true;

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(visited[i][j] == 0)
                    if(checkCycle(grid, visited, i, j, '$', -1)) return true;
            }
        }

        return false;
    }
};