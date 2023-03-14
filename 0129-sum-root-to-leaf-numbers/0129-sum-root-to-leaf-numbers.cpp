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
    void rec(TreeNode*root,int tmp,int &ans)
    {
        if(!root) return ;
        tmp=tmp*10+root->val;
        if(!root->left&& !root->right) {
            ans+=tmp;
            return;
        }
        rec(root->left,tmp,ans);
        rec(root->right,tmp,ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans=0,tmp=0;
        rec(root,tmp,ans);
        return ans;
    }
};