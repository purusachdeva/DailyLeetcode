class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto word : words) {
            string copy = word;
            reverse(copy.begin(), copy.end());

            if(copy == word) return word;
        }

        return "";
    }
};