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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int row = 0, col = 0;
        ListNode* temp = head;
        int maxRow = m, maxCol = n, minRow = 0, minCol = 0;

        while (temp) {
            // right
            while (temp && col < maxCol) {
                ans[row][col] = temp->val;
                col++;
                temp = temp->next;
            }
            col--;
            row++;
            minRow++;

            // down
            while (temp && row < maxRow) {
                ans[row][col] = temp->val;
                row++;
                temp = temp->next;
            }
            row--;
            col--;
            maxCol--;

            // left
            while (temp && col >= minCol) {
                ans[row][col] = temp->val;
                col--;
                temp = temp->next;
            }
            col++;
            row--;
            maxRow--;

            // up
            while (temp && row >= minRow) {
                ans[row][col] = temp->val;
                row--;
                temp = temp->next;
            }
            row++;
            col++;
            minCol++;
        }

        return ans;
    }
};