class Solution {
private:
    int convertToMappedVal(vector<int> mapping, int x) {
        int newNum = 0;
        int place = 1;

        if (x == 0) newNum = mapping[0];

        while (x > 0) {
            newNum = mapping[x % 10]*place + newNum;
            place *= 10;
            x /= 10;
        }

        return newNum;
    }

    bool static cmp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }

public:

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> v;
        for(auto i : nums) v.push_back({i, convertToMappedVal(mapping, i)});

        sort(v.begin(), v.end(), cmp);

        for(int i = 0; i < v.size(); i++) {
            nums[i] = v[i].first;
        }

        return nums;
    }
};