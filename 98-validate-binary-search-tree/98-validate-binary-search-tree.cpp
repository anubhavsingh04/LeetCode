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
   
    bool isValidBST(TreeNode* root) {
            return isvalid(root,LLONG_MIN,LLONG_MAX);
    }
    bool isvalid(TreeNode*root,long long int mini,long long int maxi)
    {
        if(root==NULL)
            return true;
        if(root->val>=maxi|| root->val<=mini) 
            return false;
        return isvalid(root->left,mini,root->val)&&isvalid(root->right,root->val,maxi);
    }
};



// BST will be valid only if inorder traversal will give sorted array TC: O(n) SC: O(n)
// class Solution {
// public:
//    void inorder(TreeNode*root,vector<int>&ans)
//    {
//        if(!root) return;
//        inorder(root->left,ans);
//        ans.push_back(root->val);
//        inorder(root->right,ans);
//    }
//     bool isValidBST(TreeNode* root) {
//         vector<int>v;
//         inorder(root,v);
//         for(int i=1;i<v.size();i++)
//         {
//             if(v[i]<=v[i-1]) // if not in order  
//                 return false;
//         }
//         return true;
//     }
// };



// class Solution {
//     bool flag=true;
//     vector<int>v;
// public:
//     void inorder(TreeNode*root)
//     {
//         if(root==NULL)
//             return;
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
//     bool isSorted(vector<int>v)
//     {
//         for(int i=1;i<v.size();i++)
//         {
//             if(v[i]<=v[i-1])
//             {
//                 flag=false;
//                 break;
//             }
//         }
//         if(flag==false)
//             return false;
//         return true;
//     }
//     bool isValidBST(TreeNode* root) {
//         inorder(root);
//         return isSorted(v);
//     }
// };