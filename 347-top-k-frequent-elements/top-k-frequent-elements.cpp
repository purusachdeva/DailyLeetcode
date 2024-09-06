class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (auto i : nums) freq[i]++;

        vector<pair<int,int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        int count = 0;
        vector<int> ans;

        for (auto i : freqVec) {
            if (count == k) break;

            ans.push_back(i.first);
            count++;
        }

        return ans;
    }
};