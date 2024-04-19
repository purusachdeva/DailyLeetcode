class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    // left
                    if(j == 0 || grid[i][j-1] == 0) {
                        count++;
                    }

                    // right
                    if(j == grid[0].size() - 1 || grid[i][j+1] == 0) {
                        count++;
                    }

                    // top
                    if(i == 0 || grid[i-1][j] == 0) {
                        count++;
                    }

                    // bottom
                    if(i == grid.size() - 1 || grid[i+1][j] == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};