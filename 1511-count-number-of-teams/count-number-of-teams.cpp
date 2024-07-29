class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;

        for(int i = 0; i < rating.size(); i++) {

            int rightLess = 0, rightMore = 0, leftLess = 0, leftMore = 0;

            for (int j = i + 1; j < rating.size(); j++) {
                if (rating[i] < rating[j]) rightMore++;
                else rightLess++;
            }

            for(int j = 0; j < i; j++) {
                if (rating[i] < rating[j]) leftMore++;
                else leftLess++;
            }

            ans += (leftLess * rightMore) + (rightLess * leftMore);
        }

        return ans;
    }
};