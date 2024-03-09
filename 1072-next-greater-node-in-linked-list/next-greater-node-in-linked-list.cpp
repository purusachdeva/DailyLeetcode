/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;

        while(temp != NULL) {
            vec.push_back(temp->val);
            temp = temp->next;
        }

        stack<int> st;
        vector<int> ans(vec.size(), 0);
        st.push(0);

        for(int i = vec.size()-1; i >= 0; i--) {
            while(st.top() != 0&& st.top() <= vec[i]) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(vec[i]);
        }

        return ans;
    }
};