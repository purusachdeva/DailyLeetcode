class Solution {
public:
    bool valid(string s) {
        stack<char> st;

        for(auto i : s) {
            if (i == '(') st.push(i);

            else if(i == ')') {
                if(st.top() == '(') st.pop();
                else return false;
            }
        }

        return true;
    }

    void generateParenthesisHelper(int left, int right, int n, string s, vector<string>& result) {
        if(s.length() == n * 2) {
            result.push_back(s);
        }

        if(left < n) 
            generateParenthesisHelper(left + 1, right, n, s + '(', result);

        if(right < left)
            generateParenthesisHelper(left, right + 1, n, s + ')', result);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;

        generateParenthesisHelper(0, 0, n, "", result);
        vector<string> ans;
        for(auto i : result) {
            if (valid(i)) ans.push_back(i);
        }

        return ans;
    }
};