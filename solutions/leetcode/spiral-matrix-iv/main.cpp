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
    const vector<array<int, 2>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

   public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int i = 0, j = 0, d = 0;
        auto p = head;
        while (p) {
            mat[i][j] = p->val;
            p = p->next;
            auto [di, dj] = directions[d];
            int ii = i + di, jj = j + dj;
            if (ii < 0 || ii >= m || jj < 0 || jj >= n || mat[ii][jj] != -1) {
                d = (d + 1) % 4;
                ii = i + directions[d][0];
                jj = j + directions[d][1];
            }
            i = ii, j = jj;
        }
        return mat;
    }
};
