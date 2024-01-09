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
    void inorder(TreeNode* root,vector<int>&a)
    {
        if(!root ) return;
        inorder(root->left,a);
        if(!root->left && !root->right) a.push_back(root->val);
        inorder(root->right,a);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a,b;
        inorder(root1,a);
        inorder(root2,b);
        return a==b;
    }
};