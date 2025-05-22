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
    int kthSmallest(TreeNode* root, int k) {
        int k_smallest = INT_MIN;
        int cnt = 0;
        find(root, k, cnt, k_smallest);
        return k_smallest;
    }
    void find(TreeNode* node, int k, int& cnt, int& k_smallest) {
        if (node == NULL || cnt >= k)
            return;

        find(node->left, k, cnt, k_smallest);

        cnt++;
        if (cnt == k) {
            k_smallest = node->val;
            return;
        }

        find(node->right, k, cnt, k_smallest);
    }
};