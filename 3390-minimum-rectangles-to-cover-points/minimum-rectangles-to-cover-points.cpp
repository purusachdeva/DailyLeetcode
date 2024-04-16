class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());

        int count = 1, start = points[0][0];
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] - start > w){
                start = points[i][0];
                count++;
            }
        }
        
        return count;
    }
};