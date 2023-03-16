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
    TreeNode* rec(vector<int>& inorder, vector<int>& postorder,int &postidx,int instart,int inend,unordered_map<int,int>&mp)
    {
        if(instart>inend) return NULL;
        int val=postorder[postidx--];
        int pos=mp[val];
        TreeNode*root=new TreeNode(val);
        root->right=rec(inorder,postorder,postidx,pos+1,inend,mp);   // sequence is imp
        root->left=rec(inorder,postorder,postidx,instart,pos-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int instart=0,inend=n-1,postidx=n-1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        return rec(inorder,postorder,postidx,instart,inend,mp);
    }
};