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
    void dfs(TreeNode*root,string &s)
    {
        if(!root||(!root->left && !root->right)) return;
        if(!root->left && root->right)
        {
            s+="()";
        }
        if(root->left)
        {
            s+='('+to_string(root->left->val);
            dfs(root->left,s);
            s+=')';
        }
        if(root->right)
        {
            s+='('+to_string(root->right->val);
            dfs(root->right,s);
            s+=')';
        }
    }
    string tree2str(TreeNode* root) {
        if(!root) return "";
        string ans=to_string(root->val);
        dfs(root,ans);
        return ans;
    }
};