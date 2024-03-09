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

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = length(head);

        int partLen = len/k;
        int remaining = len%k;

        vector<int> partLength(k, partLen);
        for(int i = 0; i < partLength.size(); i++) {
            if(remaining > 0) {
                partLength[i]++;
                remaining--;
            }
        }

        vector<ListNode*> ans;

        ListNode* temp = head;
        
        for(int i = 0; i < partLength.size(); i++) {
            ans.push_back(temp);
            while(partLength[i] != 1 && temp != NULL) {
                temp = temp->next;
                partLength[i]--;
            }

            if (temp) {
                ListNode* nexT = temp->next;
                temp->next = NULL;
                temp = nexT;
            }
        }

        return ans;
    }
};