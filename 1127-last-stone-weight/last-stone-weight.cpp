class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;

        for(auto i : stones) pq.push(i);

        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if (x == y) continue;
            (x > y) ? pq.push(x - y) : pq.push(y - x);
        }

        return (pq.size() != 0) ? pq.top() : 0;
    }
};