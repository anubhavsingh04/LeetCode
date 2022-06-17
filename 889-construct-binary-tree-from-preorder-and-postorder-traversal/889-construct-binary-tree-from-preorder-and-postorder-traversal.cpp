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
    TreeNode*solve(vector<int>&preorder,int prestart,int preend,
                   vector<int>&postorder,int poststart,int postend)
    {
        if(prestart>preend)
            return NULL;
        TreeNode*root=new TreeNode(preorder[prestart]);
        if(prestart==preend)
            return root;
        int pos=m[preorder[prestart+1]]; // postorder me root ke agle element ka index 
        int numleft=pos-poststart+1;
        root->left=solve(preorder,prestart+1,prestart+numleft,postorder,poststart,pos);
        root->right=solve(preorder,prestart+numleft+1,preend,postorder,pos+1,postend-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++)
        {
            m[postorder[i]]=i;
        }
        return solve(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
    }
};