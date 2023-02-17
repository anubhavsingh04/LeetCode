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
    void inorder(TreeNode*root,int &ans,int &prev)
    {
        if(!root) return;
        inorder(root->left,ans,prev);
        ans=min(ans,abs(root->val-prev));
        prev=root->val;
        inorder(root->right,ans,prev);
    }
    int minDiffInBST(TreeNode* root) {
        int prev=1e7;
        int ans=INT_MAX;
        inorder(root,ans,prev);
        return ans;
    }
};