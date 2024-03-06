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

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* reversed = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return reversed;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast != NULL) slow = slow->next;

        slow = reverseList(slow);

        fast = head;

        while(slow && fast) {
            if(slow->val != fast->val) return false;

            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};