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
// public:
//     int sumEvenGrandparent(TreeNode* root) {
//         if(!root) return 0;
//         int sum=0;
//         if(!(root->val&1))
//         {
//             if(root->left!=NULL&&root->left->left!=NULL) sum+=root->left->left->val;
//             if(root->left!=NULL&&root->left->right!=NULL) sum+=root->left->right->val;
//             if(root->right!=NULL&&root->right->left!=NULL) sum+=root->right->left->val;
//             if(root->right!=NULL&&root->right->right!=NULL) sum+=root->right->right->val;
//         }
//         return sum + sumEvenGrandparent(root->left)+ sumEvenGrandparent(root->right);
//     }
// };

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        return func(root,NULL,NULL);
    }
    int func(TreeNode*curr,TreeNode*p,TreeNode*gp) 
    {
        if(curr==NULL) return 0;
        int sum=0;
        if(gp!=NULL&&!(gp->val&1)) // if gp is even and curr is not null
        {
            sum+=curr->val;
        }
        sum+=func(curr->left,curr,p);
        sum+=func(curr->right,curr,p);
        return sum;
    }
};