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

    void solve(TreeNode* node, int &cnt, int k, int &k_smallest)
    {
        if(node == NULL or cnt >= k)
            return;
        
        solve(node->left, cnt, k, k_smallest);

        cnt++;
        if(cnt == k)
        {
            k_smallest = node->val;
            return;
        }

        solve(node->right, cnt, k, k_smallest);
    }

    int kthSmallest(TreeNode* root, int k) {
        int k_smallest = INT_MIN;
        int cnt = 0;
        solve(root, cnt, k, k_smallest);
        return k_smallest;
    }
};