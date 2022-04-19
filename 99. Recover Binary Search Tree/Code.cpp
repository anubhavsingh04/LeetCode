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
    //TreeNode*prev=middle
public:
      TreeNode*first=NULL,*middle=NULL,*prev=NULL,*last=nullptr;
    void inorder(TreeNode*root)
    {
        if(root==NULL)return;
        inorder(root->left);
        if(prev!=NULL && root->val<prev->val)
        {
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else
                last=root;
        }
        prev=root;
        inorder(root->right);
    } 
    void recoverTree(TreeNode*root) {
      
        inorder(root);
        if(first!=NULL && last!=NULL)
            swap(first->val,last->val);
        else if(first!=NULL && middle!=NULL)
            swap(first->val,middle->val);
    }
};