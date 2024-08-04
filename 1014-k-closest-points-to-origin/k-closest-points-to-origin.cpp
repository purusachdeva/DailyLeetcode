class Solution {
    struct Compare {
        bool operator()(const std::vector<int>& a, const std::vector<int>& b) {
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        }
    };

    int dist(vector<int> v) {
        return v[0]*v[0] + v[1]*v[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        for(auto i : points) {
            if (pq.size() >= k) {
                if (dist(pq.top()) > dist(i)) {
                    pq.pop();
                    pq.push(i);
                }
            }

            else pq.push(i);
        }

        vector<vector<int>> ans;

        while (ans.size() != k) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};