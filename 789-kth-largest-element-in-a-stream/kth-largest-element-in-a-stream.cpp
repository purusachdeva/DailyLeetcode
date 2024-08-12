class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto i : nums) {
            if (pq.size() >= k) {
                if (pq.top() < i) {
                    pq.push(i);
                    pq.pop();
                }
            } else pq.push(i);
        }
    }
    
    int add(int val) {
        if (pq.size() >= k) {
            if (pq.top() < val) {
                pq.pop();
                pq.push(val);
            }
        } else pq.push(val);

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */