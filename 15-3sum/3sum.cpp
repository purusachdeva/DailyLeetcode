class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int k, int i) {
        int a = 0, b = nums.size() - 1;

        vector<vector<int>> ans;

        

        while(a < b) {
            if(a == i) a++;
            else if(b == i) b--;

            else if(nums[a] + nums[b] < k) a++;
            
            else if(nums[a] + nums[b] > k) b--;

            else if(nums[a] + nums[b] == k) {
                ans.push_back({nums[a], nums[b]});
                a++;
                b--;
            }
        }

        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0) {
                if(nums[i] == nums[i - 1]) continue;
            }
            vector<vector<int>> comp = twoSum(nums, -nums[i], i);

            if(comp.size())
                for(auto ele : comp) {
                    ele.push_back(nums[i]);
                    sort(ele.begin(), ele.end());
                    ans.insert(ele);
                } 
        }

        vector<vector<int>> real(ans.begin(), ans.end());

        return real;
    }
};