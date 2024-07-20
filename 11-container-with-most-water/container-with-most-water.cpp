class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = 0;

        while(i < j) {
            int area = (j - i) * min(height[i], height[j]);
            
            if(height[i] < height[j]) i++; 
            else j--;

            ans = max(area, ans);
        }

        return ans;
    }
};