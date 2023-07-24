/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        if (n == 1) return {new TreeNode(0)};

        vector<TreeNode*> result;

        for (int i = 1; i < n - 1; i += 2) {
            auto left = allPossibleFBT(i);
            auto right = allPossibleFBT(n - 1 - i);

            for (auto l : left) {
                for (auto r : right) {
                    result.push_back(new TreeNode(0, l, r));
                }
            }
        }

        return result;
    }
};
