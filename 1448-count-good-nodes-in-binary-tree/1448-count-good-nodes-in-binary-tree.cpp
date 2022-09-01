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
    // int ans=0;
    void preorder(TreeNode*root,int maxi,int &ans)
    {
        if(!root)return;
        if(root->val>=maxi) {
            ans++;
            maxi=root->val;
        }
        preorder(root->left,maxi,ans);
        preorder(root->right,maxi,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        preorder(root,root->val,ans);
        return ans;
    }
};




// class Solution {
// public:
//     int preorder(TreeNode*root,int maxi)
//     {
//         if(!root)return 0;
//         int ans=0;
//         if(root->val>=maxi) ans++,maxi=root->val;
//         ans+=preorder(root->left,maxi);
//         ans+=preorder(root->right,maxi);
//         return ans;
//     }
//     int goodNodes(TreeNode* root) {
//         return preorder(root,root->val);
//     }
// };