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
        int l = 0;
        while(head != NULL) {
            l++;
            head = head->next;
        }

        return l;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        int n = length(head);
        k = k % n;

        if(k == 0) return head;

        ListNode* temp = head;

        int i = 0;
        while(i < n - k - 1) {
            temp = temp->next;
            i++;
        }

        ListNode* tail = temp;
        ListNode* newHead = temp->next;

        while(temp->next != NULL) temp = temp->next;

        temp->next = head;
        tail->next = NULL;
        
        return newHead;
    }
};