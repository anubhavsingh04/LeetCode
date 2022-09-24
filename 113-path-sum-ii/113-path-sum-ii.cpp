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
    void dfs(TreeNode*root,int target,int sum,vector<int>v,vector<vector<int>>&ans)
    {
        if(!root) return;
        sum+=root->val;
        v.push_back(root->val);
        if(!root->left && !root->right && sum==target)
        {
            ans.push_back(v);
        }
        dfs(root->left,target,sum,v,ans);
        dfs(root->right,target,sum,v,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        int sum=0;
        dfs(root,target,sum,v,ans);
        return ans;
    }
};