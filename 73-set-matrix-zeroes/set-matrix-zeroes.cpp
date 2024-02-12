class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> points;

        // Identify Points
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    pair<int,int> p;
                    p.first = i;
                    p.second = j;

                    points.push_back(p);
                }
            }
        }

        // Set 0 in the rows and columns
        for(auto p : points) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][p.second] = 0;
            }

            for(int j = 0; j < matrix[0].size(); j++) {
                matrix[p.first][j] = 0;
            }
        }

        
    }
};