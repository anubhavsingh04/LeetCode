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

// Using recursion: right left then modify the root

class Solution {
public:
    TreeNode*prev=NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root; // when we backtrack then we will se values will be assigned as asked 
    }
};



// using stack TC: O(n) SC: O(n)

// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         stack<TreeNode*>st;
//         if(!root) return;
//         st.push(root);
//         while(!st.empty())
//         {
//             TreeNode*curr=st.top();
//             st.pop();
//             if(curr->right)
//                 st.push(curr->right);
//             if(curr->left)
//                 st.push(curr->left);
//             if(!st.empty())
//             curr->right=st.top();
//             curr->left=NULL;
//         }
//     }
// };






// using morris traversal TC: O(n) space: O(1)

// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         TreeNode*curr=root;
//         while(curr!=NULL)
//         {
//             if(curr->left)
//             {
//                 TreeNode*prev=curr->left;
//                 while(prev->right)
//                     prev=prev->right;
//                 prev->right=curr->right;
//                 curr->right=curr->left;
//                 curr->left=NULL;
//             }
//             curr=curr->right;
//         }
//     }
// };
