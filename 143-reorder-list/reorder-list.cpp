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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode* temp = head;
        int l = 0;
        stack<ListNode*> s;

        while (temp != NULL) {
            s.push(temp);
            temp = temp->next;
            l++;
        }
        
        temp = head;
        int i = 0;
        while (i < l/2) {
            ListNode* next = s.top();
            s.pop();

            next->next = temp->next;
            temp->next = next;

            temp = next->next;
            i++;
        }
        
        temp->next = NULL;
    }
};