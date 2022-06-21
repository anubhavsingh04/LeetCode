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

// Bruteforce
class Solution {
public:
    vector<int> v;
    int i=0;
    void inorder(TreeNode*root)
    {
        if(!root) return ;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    void inorder2(TreeNode*root)
    {
        if(!root) return;
        inorder2(root->left);
        if(v[i]!=root->val)
            swap(root->val,v[i]);
        i++;
        inorder2(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(v.begin(),v.end());
        inorder2(root);
    }
};



// class Solution {
//     //TreeNode*prev=middle
// public:
//       TreeNode*first=NULL,*middle=NULL,*prev=NULL,*last=nullptr;
//     void inorder(TreeNode*root)
//     {
//         if(root==NULL)return;
//         inorder(root->left);
//         if(prev!=NULL && root->val<prev->val)
//         {
//             if(first==NULL)
//             {
//                 first=prev;
//                 middle=root;
//             }
//             else
//                 last=root;
//         }
//         prev=root;
//         inorder(root->right);
//     } 
//     void recoverTree(TreeNode*root) {
      
//         inorder(root);
//         if(first!=NULL && last!=NULL)
//             swap(first->val,last->val);
//         else if(first!=NULL && middle!=NULL)
//             swap(first->val,middle->val);
//     }
// };





// Bruteforce
// class Solution {
// public:
//     vector<int> v;
//     int i=0;
//     void inorder(TreeNode* root){
//         if(!root) return;
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
//     void check(TreeNode* root){
//         if(!root) return;
//         check(root->left);
//         if(v[i]!=root->val) swap(v[i],root->val);
//         i++;
//         check(root->right);
//     }
//     void recoverTree(TreeNode* root) {
//         inorder(root);
//         sort(v.begin(),v.end());
//         check(root);
//     }
// };