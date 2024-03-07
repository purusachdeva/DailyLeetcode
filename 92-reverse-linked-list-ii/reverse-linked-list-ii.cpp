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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        int i = 1;

        ListNode* temp = head;
        int len = 0;

        while(temp) {
            len++;
            temp = temp->next;
        }
        
        temp = head;

        while(i < left - 1) {
            temp = temp->next;
            i++;
        }

        ListNode* firstT = temp;
        ListNode* currentSecondH = temp->next;

        while(i < right) {
            temp = temp->next;
            i++;
        }

        ListNode* currentSecondT = temp;
        ListNode* thirdH = temp->next;

        if(left == 1) {
            currentSecondH = firstT;
            currentSecondT->next = NULL;
            ListNode* reversedH = reverseList(firstT);
            if(right != len) currentSecondH->next = thirdH;

            firstT->next = thirdH;
            return reversedH;
        }

        currentSecondT->next = NULL;
        ListNode* reversedH = reverseList(currentSecondH);
        
        firstT->next = reversedH;
        currentSecondH->next = thirdH;

        return head;
    }
};