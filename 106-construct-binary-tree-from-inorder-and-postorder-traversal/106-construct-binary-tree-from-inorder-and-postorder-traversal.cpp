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
// class Solution {
// public:
//     unordered_map<int,int>m;
//     TreeNode* solve(vector<int>&inorder,int instart,int inend,vector<int>&postorder,
//                int &postindex)
//     {
//         if(instart>inend)
//         {
//             return NULL;
//         }
//         TreeNode*root=new TreeNode(postorder[postindex--]);
//         int pos=m[root->val];
//         root->right=solve(inorder,pos+1,inend,postorder,postindex);
//         root->left=solve(inorder,instart,pos-1,postorder,postindex);
//         return root;
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int postindex=postorder.size()-1;
//         for(int i=0;i<inorder.size();i++){
//             m[inorder[i]]=i;
//         }
//         return solve(inorder,0,postorder.size()-1,postorder,postindex);
//     }
// };





class Solution {
public:
    TreeNode* solve(vector<int>&inorder,int instart,int inend,vector<int>&postorder,
               int poststart,int postend,unordered_map<int,int>&m)
    {
        if(instart>inend||poststart>postend)
        {
            return NULL;
        }
        TreeNode*root=new TreeNode(postorder[postend]);
        int pos=m[root->val];
        int numleft=(pos-instart);
        root->left=solve(inorder,instart,pos-1,postorder,poststart,poststart+numleft-1,m);
        root->right=solve(inorder,pos+1,inend,postorder,poststart+numleft,postend-1,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
    }
};