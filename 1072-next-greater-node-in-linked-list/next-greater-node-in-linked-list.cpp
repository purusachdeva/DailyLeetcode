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

        vector<int> ans;
        ListNode* temp = head;

        while(temp != NULL) {
            ListNode* temp1 = temp;
            int bigger = 0;
            while(temp1 != NULL) {
                if(temp1->val > temp->val) {
                    bigger = temp1->val;
                    break;
                }
                temp1 = temp1->next;
            }

            ans.push_back(bigger);
            temp = temp->next;
        }

        return ans;
    }
};