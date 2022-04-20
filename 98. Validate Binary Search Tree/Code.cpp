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
    bool flag=true;
    vector<int>v;
public:
    void inorder(TreeNode*root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool isSorted(vector<int>v)
    {
        for(int i=1;i<v.size();i++)
        {
            if(v[i]<=v[i-1])
            {
                flag=false;
                break;
            }
        }
        if(flag==false)
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return isSorted(v);
    }
};