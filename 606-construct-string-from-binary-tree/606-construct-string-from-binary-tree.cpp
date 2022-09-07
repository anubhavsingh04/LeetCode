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
// we will add () if leftdoes not exist and righ child exist i.e. root->left==NULL && root->right!=NULL
class Solution {
public:
    void dfs(TreeNode*root,string &s)
    {
        if(!root) return;
        s+=to_string(root->val);
        if(root->left==NULL && root->right!=NULL)
        {
            s+="()";
        }
        if(root->left)
        {
            s+='(';
            dfs(root->left,s);
            s+=')';
        }
        if(root->right)
        {
            s+='(';
            dfs(root->right,s);
            s+=')';
        }
    }
    string tree2str(TreeNode* root) {
        string ans="";
        dfs(root,ans);
        return ans;
    }
};