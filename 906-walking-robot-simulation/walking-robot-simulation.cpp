class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, dir = 0;
        int maxDist = 0;

        set<pair<int, int>> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }

        for (auto command : commands) {
            if (command == -2)
                dir = (dir + 3) % 4;
            
            else if (command == -1)
                dir = (dir + 1) % 4;
            
            else {
                for (int i = 0; i < command; ++i) {
                    int newX = x + directions[dir].first;
                    int newY = y + directions[dir].second;

                    if (obstacleSet.find({newX, newY}) == obstacleSet.end()) {
                        x = newX;
                        y = newY;
                        maxDist = max(maxDist, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }

        return maxDist;
    }
};