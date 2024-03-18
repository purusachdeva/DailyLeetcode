class Solution {
public:
    void checkCondition(vector<vector<int>>& intervals, int i) {
        if(i == intervals.size() - 1) return;

        if(intervals[i][1] < intervals[i+1][0]) {
            checkCondition(intervals, i + 1);
        }
            
        else {
            if(intervals[i + 1][1] > intervals[i][1]) {
                intervals[i][1] = intervals[i+1][1];
            }
            
            for(int j = i + 1; j < intervals.size() - 1; j++) 
                intervals[j] = intervals[j+1];
                
            intervals.pop_back();

            checkCondition(intervals, i );
        }
    }
    
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        checkCondition(intervals, 0);
        return intervals;
    }
};