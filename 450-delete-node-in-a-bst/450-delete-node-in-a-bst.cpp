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
    TreeNode*solve(TreeNode*root)
    {
        if(root->left==NULL)
            return root->right;
        if(root->right==NULL)
            return root->left;
        TreeNode* rightchild=root->right;
        TreeNode* leftvaleka_rightmost=findrightmost(root->left);
        leftvaleka_rightmost->right=rightchild;
        return root->left;
    }
    
    TreeNode*findrightmost(TreeNode*root)
    {
        if(root->right==NULL)
            return root;
        return findrightmost(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key==root->val) return solve(root);
        TreeNode*curr=root;
        while(root)
        {
            if(key<root->val)
            {
                if(root->left!=NULL&&root->left->val==key)
                {
                     root->left=solve(root->left);
                    break;
                }
                else 
                    root=root->left;   
            }
            else 
            {
                if(root->right!=NULL&&root->right->val==key)
                {
                    root->right=solve(root->right);
                    break;
                }
                else 
                    root=root->right;
            }
        }
        return curr;
    }
};