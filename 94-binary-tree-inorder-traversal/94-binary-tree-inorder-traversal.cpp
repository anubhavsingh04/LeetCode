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
    vector<int>v;
public:
    void inorder(TreeNode*root)
    {
        if(root==NULL)
            return ;
         inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return v;
    }
};



// Morris traversal (threaded binary tree)


// class Solution {
//     vector<int>v;
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         TreeNode*curr=root;
//         while(curr!=NULL)
//         {
//             if(curr->left==NULL)
//             {
//                 ans.push_back(curr->val);
//                 curr=curr->right;
//             }
//             else 
//             {
//                 TreeNode*prev=curr->left;
//                 while(prev->right&&prev->right!=curr)
//                 {
//                     prev=prev->right;
//                 }
//                 if(prev->right==NULL)
//                 {
//                     prev->right=curr;
//                     curr=curr->left;
//                 }
//                 else // prev ka right agr curr ke equal ho gya ho 
//                 {
//                     prev->right=NULL;
//                     ans.push_back(curr->val);
//                     curr=curr->right;
//                 }
//             }
//         }
//         return ans;
//     }
// };
    
    
    

    
// Iterative inorder traversal 

// class Solution {
//     vector<int>v;
// public:
    
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         if(!root) return ans;
//         stack<TreeNode*>st;
//         TreeNode*curr=root;
//         while(true)
//         {
//             if(curr!=NULL){
//                  st.push(curr);
//                 curr=curr->left;
//             }
//             else {
//                 if(st.empty()) break;
                
//                     curr=st.top();
//                     st.pop();
//                     ans.push_back(curr->val);
//                     curr=curr->right;
//             }   
//         }
//         return ans;
//     }
// };