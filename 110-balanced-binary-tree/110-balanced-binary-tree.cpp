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
// Recursive approach optimal
class Solution {
public:
    int dfsheight(TreeNode*root){
        if(!root) return 0;
        int lh=dfsheight(root->left);
        if(lh==-1) return  -1;
        int rh=dfsheight(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
         return (1+max(lh,rh));
    }
    bool isBalanced(TreeNode* root){
        return dfsheight(root)!=-1;
    }
};



// 
// class Solution {
// public:
//     bool ans;
//     int checkBalance(TreeNode* root){
//         if(!root)
//             return 0;
//         if(!ans) 
//             return 0;
//         int leftSubTree = checkBalance(root->left);
//         int rightSubTree = checkBalance(root->right);
//         if(abs(leftSubTree-rightSubTree) > 1){
//             ans = false;
//         }
//         return 1 + max(leftSubTree, rightSubTree);
//     }
//     bool isBalanced(TreeNode* root){
//         ans = true;
//         int temp = checkBalance(root);
//         return ans;
//     }
// };