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
// height hoti hai leaf to that node dis
// pata kro kis subtree ki height jada hai 
// jis subtree ki height jada hogi usi me deepest leaf lie krega
// jis node ke corresponding left aur right subtree ki heights same hongi
// vahi leaf ka common lca hoga 

class Solution {
public:
    int height(TreeNode*root){
        if(!root)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int left=height(root->left);
        int right=height(root->right);
        if(left<right)
            return lcaDeepestLeaves(root->right);
        else if(left>right)
            return lcaDeepestLeaves(root->left);
        else 
            return root;
    }
};


// class Solution {
// public:
//     int dfs(TreeNode*root,TreeNode*&ans,int l,int &maxdepth)
//     {
//         if(!root) return l-1;
//         maxdepth=max(maxdepth,l);
//         int left=dfs(root->left,ans,l+1,maxdepth);
//         int right=dfs(root->right,ans,l+1,maxdepth);
//         if(left==maxdepth&&right==maxdepth)
//             ans=root;
//         return max(left,right);
//     }
//     TreeNode* lcaDeepestLeaves(TreeNode* root) {
//         TreeNode*ans;
//         int maxdepth=0;
//         dfs(root,ans,0,maxdepth);
//         return ans;
//     }
// };