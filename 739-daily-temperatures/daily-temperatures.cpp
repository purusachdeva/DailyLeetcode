class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> ans(temperatures.size(), 0);

        st.push({temperatures[0], 0});
        for(int i = 1; i < temperatures.size(); i++) {
            
            while(!st.empty() && temperatures[i] > st.top().first) {
                ans[st.top().second] = (i - st.top().second);
                st.pop();
            }

            st.push({temperatures[i], i});
        }

        return ans;
    }
};