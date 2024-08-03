class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() != arr.size()) return false;

        for(int i = 0; i < target.size(); i++) {
            bool flag = false;
            for(int j = i; j < arr.size(); j++) {
                if (arr[j] == target[i]) {
                    flag = true;
                    reverse(arr.begin() + i, arr.begin() + j + 1);
                    break;
                }
            }
            if (!flag) return false;
        }

        return true;
    }
};