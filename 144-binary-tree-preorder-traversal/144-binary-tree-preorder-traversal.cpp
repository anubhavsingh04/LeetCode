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
// class Solution {
//     vector<int>v;
// public:
//     void preorder(TreeNode*root)
//     {
//         if(root==nullptr)
//             return;
//         v.push_back(root->val);
//         preorder(root->left);
//         preorder(root->right);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         preorder(root);
//         return v;
//     }
// };

class Solution {
    vector<int>v;
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*curr=st.top();
            st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            ans.push_back(curr->val);
        }
        return ans;
    }
};