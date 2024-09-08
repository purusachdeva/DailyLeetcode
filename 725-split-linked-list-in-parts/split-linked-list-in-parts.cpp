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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;

        int length = 0;
        while (temp) {
            temp = temp->next;
            length++;
        }

        int size = length / k;
        int remainingSize = length % k;

        vector<ListNode*> ans(k, NULL);

        temp = head;
        ListNode* prev = temp;

        for (int i = 0; i < k; i++) {
            ListNode* newPart = temp;

            int currentSize = size;
            if (remainingSize > 0) {
                remainingSize--;
                currentSize++;
            }

            int j = 0;
            while (j < currentSize){
                prev = temp;
                if (temp) temp = temp->next;
                j++;
            }

            if (prev) prev->next = NULL;

            ans[i] = newPart;
        }

        return ans;
    }
};