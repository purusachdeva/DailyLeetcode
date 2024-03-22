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
    ListNode* reverseLL(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* reversed = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;

        return reversed;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reversed = reverseLL(slow->next);

        while(reversed != NULL) {
            if(head->val != reversed->val) return false;

            head = head->next;
            reversed = reversed->next;
        }

        return true;
    }
};