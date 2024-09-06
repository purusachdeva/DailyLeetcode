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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s(nums.begin(), nums.end());

        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp) {
            if (s.find(temp->val) != s.end()) {
                if (!prev) head = head->next;
                else prev->next = temp->next;
            } else {
                prev = temp;
            }

            temp = temp->next;
        }

        return head;
    }
};