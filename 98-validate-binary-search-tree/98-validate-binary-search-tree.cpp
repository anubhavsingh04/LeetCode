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
// bst valid tab hoga jab uska inorder travresal sorted array dega 

class Solution {
public:
   void inorder(TreeNode*root,vector<int>&ans)
   {
       if(!root) return;
       inorder(root->left,ans);
       ans.push_back(root->val);
       inorder(root->right,ans);
   }
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        for(int i=1;i<v.size();i++)
        {
            if(v[i]<=v[i-1]) // agar vector me agla element chota hai means sorted order me nhi h elemen
                return false;
        }
        return true;
    }
};



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