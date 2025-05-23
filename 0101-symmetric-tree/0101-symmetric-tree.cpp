/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return ismirror(root->left, root->right);
    }

    bool ismirror(TreeNode* node1, TreeNode* node2)
    {
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;

        return (node1->val == node2->val && ismirror(node1->left, node2->right) && ismirror(node1->right, node2->left));
    }
};