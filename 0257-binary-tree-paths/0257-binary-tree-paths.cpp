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
    void  solve(TreeNode*root,vector<string>&ans,string curr)
    {
        if(!root) return ;
        if(root->left||root->right) 
            curr+=to_string(root->val)+"->";
        else{
            curr+=to_string(root->val);
            ans.push_back(curr);
        }
        solve(root->left,ans,curr);
        solve(root->right,ans,curr);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string curr="";
        solve(root,ans,curr);
        return ans;
    }
};

// root to node path in binary tree  this is another similar question 

// class Solution{
//         public:
//         bool solve(TreeNode*root,vector<int>&ans,int x)
//         {
//             if(!root) return false;
//             ans.push_back(root->val);
//             if(root->val==x)
//                 return true;
//             if(solve(root->left,ans,x)||solve(root->right,ans,x))
//                 return true;
//             ans.pop_back();
//             return false ;
//         }
//         vector<int> ispath(TreeNode*root,int x)
//             if(!root)return false;
//                 vector<int>ans;
//           solve(root ,ans,x);
//             return ans;
//     }
// };


