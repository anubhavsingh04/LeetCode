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
    void solve(TreeNode*root,vector<int>&ans,int level)
    {
        if(!root) return;
        
        if(ans.size()==level) ans.push_back(root->val);
        
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root,ans,0);
        return ans;
    }
};


// Har level ka last node right vieew hoga 
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int>ans;
//         if(!root) return ans;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty())
//         {
//             int sz=q.size();
//             vector<int>v;
//             for(int i=0;i<sz;i++)
//             {
//                 TreeNode*curr=q.front();
//                 q.pop();
                
//                 if(curr->left)
//                     q.push(curr->left);
//                 if(curr->right)
//                     q.push(curr->right);
                
//                 v.push_back(curr->val);
//             }
//             ans.push_back(v.back());
//         }
//         return ans;
//     }
// };