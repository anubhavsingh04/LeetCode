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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh=0,rh=0;
        TreeNode*curr=root;
        while(curr)
        {
            lh++;
            curr=curr->left;
        }
        curr=root;
        while(curr)
        {
            rh++;
            curr=curr->right;
        }
        
        if (lh == rh) return pow(2, lh) - 1; // for complete binary tree no of node=2^h-1
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};



// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if (!root) return 0;
//         int lh=leftheight(root->left);
//         int rh=rightheight(root->right);
//         return 1+countNodes(root->left)+countNodes(root->right);
//     }
    
//     int leftheight(TreeNode*root)
//     {
//         int x=1;
//         while(root){
//             x++;
//           root=root->left;
//         }
//         return x;
//     }
//     int rightheight(TreeNode*root)
//     {
//         int x=1;
//         while(root){
//             x++;
//             root=root->right;
//         }
//         return x;
//     }
// };




// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if (!root) return 0;
//         return 1+countNodes(root->left)+countNodes(root->right);
//     }
// };




// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if (!root) return 0;
//         int lh=height(root->left);
//         int rh=height(root->right);
//         return 1+countNodes(root->left)+countNodes(root->right);
//     }
//     int height(TreeNode*root)
//     {
//         if(!root) return 0;
//         int lh=height(root->left);
//         int rh=height(root->right);
//         return 1+max(lh,rh);
//     }
// };