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
    int maxDepth(TreeNode* root) {
        // recursive
        // if(root == nullptr) return 0;
        // int maxl = maxDepth(root->left);
        // int maxr = maxDepth(root->right);

        // return max(maxl, maxr)+1;

        // iterative
        
        if(root == nullptr) return 0;
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            cnt++;
            for(int i = 0; i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right !=nullptr) q.push(node->right);
                
            }
            
        }
        return cnt;
    }
};