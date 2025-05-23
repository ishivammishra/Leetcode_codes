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
    int sumNumbers(TreeNode* root) {
        int num = 0;
        return helper(root, num);
    }

    int helper(TreeNode* node, int num) {
        if (node == NULL)
            return 0;

        num = num * 10 + node->val;

        if (node->left == NULL and node->right == NULL)
            return num;

        return (helper(node->left, num) + helper(node->right, num));
    }
};