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
    pair<int,int> average(TreeNode*root,int &cnt)
    {
        if(root==NULL)
            return {0,0};
        pair<int,int>l=average(root->left,cnt);
        pair<int,int>r=average(root->right,cnt);
        int sum=l.first+r.first+root->val;
        int n=l.second+r.second+1;
        if(sum/n==root->val) cnt++ ;
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
         int cnt=0;
        average(root,cnt);
        return cnt;
    }
};