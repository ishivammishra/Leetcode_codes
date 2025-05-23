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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return 0;
        int sum = 0;
        range_sum(root, low, high, sum);
        return sum;
    }

    void range_sum(TreeNode* node, int low, int high, int &sum)
    {
        if(node ==nullptr) return;
        if(node->val >= low and node->val <= high) sum += node->val;

        if(low <= node->val) range_sum(node->left, low, high, sum);
        if(high >= node->val) range_sum(node->right, low, high, sum);
    }
};