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

// TC: O(n) SC: O(h) if we dont consider stack space then SC: O(1)
class Solution {
public:
    int ans=INT_MAX; 
    TreeNode*prev=NULL;
    void inorder(TreeNode*root)
    {
        if(!root) return;
        inorder(root->left);
        if(prev)
        {
            ans=min(ans,abs(prev->val-root->val));
        }
        prev=root;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};


// TC: O(n) SC: O(n)
// class Solution {
// public:
//     vector<int>v;
//     void inorder(TreeNode*root)
//     {
//         if(!root) return;
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
//     int getMinimumDifference(TreeNode* root) {
//         inorder(root);
//         int ans=INT_MAX;
//         for(int i=1;i<v.size();i++)
//         {
//             ans=min(ans,abs(v[i]-v[i-1]));
//         }
//         return ans;
//     }
// };