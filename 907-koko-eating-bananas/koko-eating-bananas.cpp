class Solution {
public:
    bool simulate(vector<int>& piles, int h, int k) {
        for(auto i : piles) {
            h -= (i / k);
            if (i % k != 0) h--;
        }

        if (h < 0) return false;

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int i = 1;
        int j = piles[piles.size() - 1];

        while (i < j) {
            int mid = (i + j) / 2;

            if (simulate(piles, h, mid)) j = mid;
            else i = mid + 1;
        }

        int mid = (i + j) / 2;

        if (simulate(piles, h, mid)) return mid;

        return -1;
    }
};