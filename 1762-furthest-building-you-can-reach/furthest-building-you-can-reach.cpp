class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> upward;

        for(int i = 0; i < heights.size() - 1; i++) {

            int diff = heights[i + 1] - heights[i];

            if(diff > 0) {
                upward.push(diff);

                if(upward.size() > ladders) {
                    int bricks_needed = upward.top();
                    upward.pop();

                    if(bricks_needed > bricks) return i;
                    else bricks -= bricks_needed;
                }
            }
        }

        return heights.size() - 1;
    }
};