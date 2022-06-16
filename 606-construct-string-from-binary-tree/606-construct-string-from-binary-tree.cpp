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
    void solve(TreeNode*root,string &ans)
    {
        if(!root||(!root->left)&&(!root->right))
            return;
        if(!root->left&&root->right)
        {
            ans+="()";
        }
        if(root->left)
        {
            ans+="("+to_string(root->left->val);
            solve(root->left,ans);
            ans+=")";
        }
        if(root->right)
        {
            ans+="("+to_string(root->right->val);
            solve(root->right,ans);
            ans+=")";
        }
        return;
    }
    string tree2str(TreeNode* root) {
        string ans="";
        if(!root) return ans;
        ans+=to_string(root->val);
        solve(root,ans);
        return ans;
    }
};