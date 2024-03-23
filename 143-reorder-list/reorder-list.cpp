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
        if(!head || !head->next) return;

        ListNode* temp = head;

        stack<ListNode*> q;

        int l = 0;
        while(temp != NULL) {
            q.push(temp);
            temp = temp->next;
            l++;
        } 

        temp = head;
        
        int i = 0;
        while(i < l/2 && temp && temp != q.top() && q.size() != 0) {
            ListNode* top = q.top();
            q.pop();
            top->next = temp->next;
            temp->next = top;

            temp = top->next;
            i++;
        }

        temp->next = NULL;
    }     
};