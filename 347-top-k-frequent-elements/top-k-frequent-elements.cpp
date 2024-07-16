class Solution {
    
    static bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second; // Use > to get top k frequent elements
    }

    public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;

        for(auto i : nums) m[i]++;

        vector<int> ans;
        int count = 0;

        vector<pair<int, int>> freqVec(m.begin(), m.end());

        sort(freqVec.begin(), freqVec.end(), cmp);

        for(auto i : freqVec) {
            if(count == k) break;

            ans.push_back(i.first);
            count++;
        }

        return ans;
    }
};