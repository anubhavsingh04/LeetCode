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
    bool dfs(TreeNode*root,int target)
    {
        if(!root) return false;
        target-=root->val;
        if(!root->left && !root->right && target==0) return true;
        if(dfs(root->left,target) || dfs(root->right,target)) return true;
        target+=root->val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int target) {
        return dfs(root,target);
    }
};