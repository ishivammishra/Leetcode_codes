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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root == nullptr) return ans;

        st.push(root);

        while(!st.empty())
        {
            root = st.top();
            st.pop();

            ans.push_back(root->val);

            if(root->right != nullptr) st.push(root->right);
            if(root->left != nullptr) st.push(root->left);
        }

        return ans;
    }
};
