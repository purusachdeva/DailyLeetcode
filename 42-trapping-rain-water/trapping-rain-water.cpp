class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];

        int ans = 0;

        while (l < r) {
            if (leftMax < rightMax) {
                l += 1;
                leftMax = max(leftMax, height[l]);
                ans += leftMax - height[l];
            }

            else {
                r -= 1;
                rightMax = max(rightMax, height[r]);
                ans += rightMax - height[r];
            }
        }

        return ans;
    }
};