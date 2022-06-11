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
    int height(TreeNode*root){
        if(!root)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int left=height(root->left);
        int right=height(root->right);
        if(left<right)
            return lcaDeepestLeaves(root->right);
        else if(left>right)
            return lcaDeepestLeaves(root->left);
        else 
            return root;
    }
    
};