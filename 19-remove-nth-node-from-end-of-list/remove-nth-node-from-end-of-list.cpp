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
    int length(ListNode* head) {
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL) {
            temp = temp -> next;
            length++;
        }

        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        int len = length(head);
        if(n > len) return head;
        if(n == len) return head->next;

        ListNode* temp = head;
        ListNode* temp1 = head;
        int nodeNum = len - n;
        int index = 0;

        while(index != nodeNum-1) {
            temp = temp->next;
            index++;
        }
        
        index = 0;
        while(index != nodeNum+1) {
            temp1 = temp1->next;
            index++;
        }

        temp->next = temp1;

        return head;
    }
};