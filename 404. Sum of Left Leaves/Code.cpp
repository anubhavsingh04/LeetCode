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
    int left(TreeNode* root){
        if (root==NULL)
            return 0;
        if ((root->left==NULL) && (root->right==NULL))
            return root->val;
        return sumOfLeftLeaves(root->right) + left(root->left);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if ((root==NULL) || ((root->left==NULL) && (root->right==NULL)))
            return 0;  
        return sumOfLeftLeaves(root->right) + left(root->left);
    }
};