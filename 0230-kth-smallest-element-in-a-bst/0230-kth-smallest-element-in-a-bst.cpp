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
    void solve(TreeNode* node, int k, int& k_small, int& cnt) {
        if (node == NULL or cnt >= k)
            return;
        
        solve(node->left, k, k_small, cnt);

        cnt++;
        if(cnt == k)
        {
            k_small = node->val;
            return;
        }

        solve(node->right, k, k_small, cnt);
    }

    int kthSmallest(TreeNode* root, int k) {
        int k_small = INT_MIN;
        int cnt = 0;
        solve(root, k, k_small, cnt);
        return k_small;
    }
};