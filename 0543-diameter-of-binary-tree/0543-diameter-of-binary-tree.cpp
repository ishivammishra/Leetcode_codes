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
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        height(root, d);

        return d;
    }
    int height(TreeNode* node, int& d) {
        if (node == nullptr)
            return 0;
        int left = height(node->left,d);
        int right = height(node->right,d);

        d = max(d, left + right);

        return max(left, right) + 1;
    }
};