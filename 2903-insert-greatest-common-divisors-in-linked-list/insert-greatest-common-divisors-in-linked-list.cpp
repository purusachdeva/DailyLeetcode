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
    int gcd(int a, int b) {
        int c = min(a, b);

        while (c > 0) {
            if (a % c == 0 && b % c == 0)
                return c;

            c--;
        }

        return 1;
    }

public:

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;

        while (temp && temp->next) {
            ListNode* temp2 = new ListNode(gcd(temp->val, temp->next->val));
            ListNode* save = temp->next;

            temp->next = temp2;
            temp2->next = save;

            temp = save;
        }

        return head;
    }
};