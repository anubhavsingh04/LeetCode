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
// using set if(k-root->val) exist in set then we will have our two sum
class Solution {
public:
   unordered_set<int>s;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(s.find(k-root->val)!=s.end())
            return true;
        s.insert(root->val);
        return findTarget(root->left,k)||findTarget(root->right,k);
    }
};



// using inorder traversal 
// store the value int the vector which will be sorted in case of bst
// then just apply two pointer like two sum problem 

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
//     bool findTarget(TreeNode* root, int k) {
//         inorder(root);
//         int i=0,j=v.size()-1;
//         while(i<j)
//         {
//             if((v[i]+v[j]) == k)
//                 return true;
//             else if((v[i]+v[j])>k)
//                 j--;
//             else
//                 i++;
//         }
//         return false;
//     }
// };



//  using bst iterator