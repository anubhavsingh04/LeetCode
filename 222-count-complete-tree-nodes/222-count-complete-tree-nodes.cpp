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
        return 1+countNodes(root->left)+countNodes(root->right);
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
        
//         int l = 1, r = 1;
//         TreeNode *ptr_r = root, *ptr_l = root;
//         while (ptr_l = ptr_l->left) l++;
//         while (ptr_r = ptr_r->right) r++;
        
//         if (l == r) return pow(2, l) - 1;
//         return 1 + countNodes(root->left) + countNodes(root->right);
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