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
    unordered_map<int,int>mp;
    TreeNode*rec(vector<int>&pre,vector<int>&post,int start,int end,int &idx)
    {
        if(start>end) return NULL;
        if(start==end) return new TreeNode(pre[idx++]);
           int pos=mp[pre[idx+1]];
        TreeNode*root=new TreeNode(pre[idx++]);
        root->left=rec(pre,post,start,pos,idx);
        root->right=rec(pre,post,pos+1,end-1,idx);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++)
        {
            mp[postorder[i]]=i;
        }
        int idx=0;
        return rec(preorder,postorder,0,postorder.size()-1,idx);
    }
};