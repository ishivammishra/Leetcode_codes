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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == NULL)
            return true;
        if (root == NULL)
            return false;

        if (sametree(root, subRoot))
            return true;

        return (isSubtree(root->left, subRoot) or
                isSubtree(root->right, subRoot));
    }

    bool sametree(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot)
            return true;

        if (root and subRoot and root->val == subRoot->val) {
            return (sametree(root->left, subRoot->left) and
                    sametree(root->right, subRoot->right));
        }

        return false;
    }
};