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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;

        while(a != 1) {
            temp = temp->next;
            a--;
            b--;
        }

        ListNode* leftTail = temp;

        while(b != 0) {
            temp = temp->next;
            b--;
        }

        ListNode* rightHead = temp->next;

        leftTail->next = list2;
        temp = list2;

        while(temp->next) {
            temp = temp->next;
        }

        temp->next = rightHead;

        return list1;
    }
};