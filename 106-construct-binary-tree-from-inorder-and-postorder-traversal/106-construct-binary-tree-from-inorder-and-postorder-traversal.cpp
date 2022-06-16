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
    unordered_map<int,int>m;
    TreeNode* solve(vector<int>&inorder,int instart,int inend,vector<int>&postorder,
               int &postindex)
    {
        if(instart>inend)
        {
            return NULL;
        }
        // int pos=m[postorder[postindex]];
        // TreeNode* root=new TreeNode(inorder[pos]);
        // postindex--;
        TreeNode*root=new TreeNode(postorder[postindex--]);
        int pos=m[root->val];
        root->right=solve(inorder,pos+1,inend,postorder,postindex);
        root->left=solve(inorder,instart,pos-1,postorder,postindex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postindex=postorder.size()-1;
        // unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(inorder,0,postorder.size()-1,postorder,postindex);
    }
};