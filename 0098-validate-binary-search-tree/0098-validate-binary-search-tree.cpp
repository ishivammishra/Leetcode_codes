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
    bool isValidBST(TreeNode* root) { return check(root, LONG_MIN, LONG_MAX); }

    bool check(TreeNode* node, long mini, long maxi) {
        if (node == NULL)
            return true;
        if (node->val <= mini or node->val >= maxi)
            return false;

        return (check(node->left, mini, node->val) and
                check(node->right, node->val, maxi));
    }
}

;