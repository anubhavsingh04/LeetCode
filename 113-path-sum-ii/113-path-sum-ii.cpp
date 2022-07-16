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

// Backtracking +recursion

class Solution {
public:
    vector<vector<int>>ans;
    void solve(TreeNode*root,int &sum,int targetSum,vector<int>&tmp)
    {
        if(!root) return;
        sum+=root->val;
        tmp.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==targetSum)
        {
            ans.push_back(tmp);
        }
        solve(root->left,sum,targetSum,tmp);
        solve(root->right,sum,targetSum,tmp);
        sum-=root->val;
        tmp.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>tmp={};
        solve(root,sum,targetSum,tmp);
        return ans;
    }
};