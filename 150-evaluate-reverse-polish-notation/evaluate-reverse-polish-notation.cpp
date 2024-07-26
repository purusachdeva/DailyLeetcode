class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(auto i : tokens) {
            if (i == "+") {
                string a = st.top();
                st. pop();
                string b = st.top();
                st.pop();
                st.push(to_string(stoi(b) + stoi(a)));
            } else if (i == "-") {
                string a = st.top();
                st. pop();
                string b = st.top();
                st.pop();
                st.push(to_string(stoi(b) - stoi(a)));
            } else if (i == "*") {
                string a = st.top();
                st. pop();
                string b = st.top();
                st.pop();
                st.push(to_string(stoi(b) * stoi(a)));
            } else if (i == "/") {
                string a = st.top();
                st. pop();
                string b = st.top();
                st.pop();
                st.push(to_string(stoi(b) / stoi(a)));
            }
            
            else st.push(i);
        }

        return stoi(st.top());
    }
};