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
    int sum=0;
    int Sum(TreeNode*root,int low, int high)
    {
        if(root==NULL)
            return 0;
        int curr=root->val;
        if(curr>=low&&curr<=high)
            sum+=curr;
        Sum(root->left,low,high);
        Sum(root->right,low,high);
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return Sum(root,low,high);
    }
};