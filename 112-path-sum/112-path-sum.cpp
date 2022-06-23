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
    int sum=0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        targetSum-=root->val;
        if(!root->left&&!root->right&&targetSum==0) return true;
        return (hasPathSum(root->left,targetSum)||hasPathSum(root->right,targetSum));
    }
};





// class Solution {
// public:
//     int sum=0;
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         return solve(root,targetSum,sum);
//     }
//      bool solve(TreeNode* root, int targetSum,int sum) {
//         if(!root) return false;
//         sum+=root->val;
//         if(root->left==NULL&&root->right==NULL&&targetSum==sum) return true;
//         return solve(root->left,targetSum,sum)||solve(root->right,targetSum,sum);
//     }
// };