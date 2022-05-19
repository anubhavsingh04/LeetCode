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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums,0,nums.size()-1);
    }
    TreeNode* func(vector<int>&nums,int s,int e)
    {
        if(s<=e)
        {
            int mid=s+(e-s)/2;
            TreeNode*node=new TreeNode(nums[mid]);
            node->left=func(nums, s, mid-1);
            node->right=func(nums, mid+1, e);
            return node;
        }
        return NULL;
    }
};