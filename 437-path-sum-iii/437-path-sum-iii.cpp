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

// O(n^2) 
// solve will find all possible path including the 
// then same function we will call for left and right subtree 

class Solution {
public:
    int ans=0;
    void solve(TreeNode*root,int targetsum,long long currsum)
    {
        if(!root) return;
        currsum+=root->val;
        if(currsum==targetsum)
            ans++;
        solve(root->left,targetsum,currsum);
        solve(root->right,targetsum,currsum);
            
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        solve(root,targetSum,0);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }
};