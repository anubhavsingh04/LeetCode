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
    bool dfs(TreeNode*root,int k,map<int,int>&m)
    {
        if(!root) return false;
        if(m.find(k-root->val)!=m.end())
        {
            return true;
        }
        m[root->val]++;
        return dfs(root->left,k,m)||dfs(root->right,k,m);
    }
    bool findTarget(TreeNode* root, int k) {
        map<int,int>m;
        return dfs(root,k,m);
    }
};