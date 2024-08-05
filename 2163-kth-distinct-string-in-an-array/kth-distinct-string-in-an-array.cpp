class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> count;
        string ans;

        for(auto s : arr) count[s]++;
        for(auto s : arr) {
            if (count[s] == 1 && k > 0) {
                k--;
                ans = s;
            } 
        }

        return k == 0 ? ans : "";
    }
};