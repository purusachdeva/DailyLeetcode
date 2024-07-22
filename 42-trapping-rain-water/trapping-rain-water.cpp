class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        
        for(int i = 1; i < height.size(); i++)
            maxLeft[i] = max(height[i-1], maxLeft[i-1]); 
            

        for(int i = height.size() - 2; i >= 0; i--)
            maxRight[i] = max(height[i+1], maxRight[i+1]);

        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            int total = min(maxLeft[i], maxRight[i]) - height[i];  
            if(total > 0) ans += total;
        }

        return ans;
    }
};