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
    int ans=0;
    int rec(TreeNode*root,int maxi,int mini)
    {
        if(!root) return 0;
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        ans=max(ans,maxi-mini);
        rec(root->left,maxi,mini);
        rec(root->right,maxi,mini);
        return ans;
    }
    int maxAncestorDiff(TreeNode* root) {
        return rec(root,-1e9,1e9);
    }
};