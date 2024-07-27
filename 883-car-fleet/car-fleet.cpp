class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<int> indices(n);
        for (int i = 0; i < n; ++i) indices[i] = i;

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return position[a] < position[b];
        });

        vector<int> sorted_speed(speed.size());
        sort(position.begin(), position.end());
        
        for (int i = 0; i < indices.size(); ++i)
            sorted_speed[i] = speed[indices[i]];

        speed = sorted_speed;

        int fleets = 1;
        float timeReq = timeReq = (target - position[n - 1])/float(speed[n - 1]);

        for(int i = n - 2; i >= 0; i--) {
            float timeReqPrev = (target - position[i])/float(speed[i]);

            if (timeReqPrev > timeReq) {
                fleets++;
            }

            timeReq = max(timeReqPrev, timeReq);
        }

        return fleets;
    }
};