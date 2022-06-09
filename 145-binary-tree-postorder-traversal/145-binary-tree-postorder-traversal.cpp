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
//     void postorder(TreeNode*root)
//     {
//         if(root==nullptr)
//             return;
//         postorder(root->left);
//         postorder(root->right);
//         v.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         postorder(root);
//         return v;
//     }
// };

// Iterative soln using single stack 
// class Solution {
//     vector<int>v;
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         if(!root) return ans;
//         stack<TreeNode*>st;
//         st.push(root);
//         while(!st.empty())
//         {
//             TreeNode*curr=st.top();
//             st.pop();
//             if(curr->left) st.push(curr->left);
//             if(curr->right) st.push(curr->right);
//             ans.push_back(curr->val);
//         }
//         return ans;
//     }
// };


// Iterative soln using two stack
class Solution {
    vector<int>v;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode*curr=st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
        }
        while(!st2.empty())
        {
            TreeNode*n=st2.top();
            st2.pop();
            ans.push_back(n->val);
        }
        return ans;
    }
};