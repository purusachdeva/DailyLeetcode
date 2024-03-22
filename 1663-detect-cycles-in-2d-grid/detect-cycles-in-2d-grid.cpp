class Solution {
public:
    bool checkCycle(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, char val, int cameFrom) {

        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0) return false;

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

        
        if(cameFrom != 3) 
            if (checkCycle(grid, visited, i + 1, j, val, 1))
                return true;

        if(cameFrom != 4) 
            if (checkCycle(grid, visited, i, j+1, val, 2))
                return true;

        if(cameFrom != 1) 
            if (checkCycle(grid, visited, i - 1, j, val, 3))
                return true;

        if(cameFrom != 2)
            if (checkCycle(grid, visited, i , j - 1, val, 4))
                return true;

        
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && checkCycle(grid,visited, i, j, '$', -1))
                    return true;
            }
        }

        return false;
    }
};