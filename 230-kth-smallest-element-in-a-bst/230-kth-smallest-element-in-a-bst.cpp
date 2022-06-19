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

// inorder of any bst gives node in sorted order 
// class Solution {
//     vector<int>v;
// public:
//     void inorder(TreeNode* root)
//     {
//         if(root==NULL) return;
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         inorder(root);
//         return v[k-1];
//     }
// };



class Solution {
public:
    int cnt=0,ans;
    void inorder(TreeNode* root,int k)
    {
        if(root==NULL) return;
        inorder(root->left,k);
        cnt++;
        if(cnt==k)
        {
            ans=root->val;
            return;
        }   
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};