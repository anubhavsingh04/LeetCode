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
// class Solution {
// public:
//     int ans=INT_MIN;
//     class nodevalue{
//       public :
//         int minval,maxval,sum;
//         bool isbst;
//     };
    
//     nodevalue maxsumhelper(TreeNode*root)
//     {
//         if(!root)
//         {
//             nodevalue n;
//             n.minval=INT_MAX;
//             n.maxval=INT_MIN;
//             n.sum=0;
//                 return n;
//         }
//         auto left=maxsumhelper(root->left);
//         auto right=maxsumhelper(root->right);
        
//         nodevalue res;
        
//         res.minval=min(root->val,min(left.minval,right.minval));
//         res.maxval=max(root->val,max(right.maxval,left.maxval));
        
//       res.isbst = left.isbst && right.isbst && (left.maxval < root->val && right.minval > root->val);
        
//         if(res.isbst)
//         {
//             res.sum=left.sum+right.sum+root->val;
//             res.minval=min(root->val,left.minval);
//             res.maxval=max(root->val,right.maxval);
//         }
//         else 
//         {
//             res.sum=max(left.sum,right.sum);
//         }
//         ans=max(ans,res.sum);
        
//         return res;
//     }
    
//     int maxSumBST(TreeNode* root) {
//         maxsumhelper(root);
//         return ans>0?ans:0;
//     }
// };





class Solution {
public:
    class bst {
    public:
      bool isbst;
      int max;
      int min;
      int sum;
    };

    bst Bst(TreeNode* root) {

      if (root == nullptr)
      {  
        bst bres;            // Base Case
        bres.isbst = true;
        bres.max = INT_MIN;
        bres.min = INT_MAX;
        bres.sum = 0;
        return bres;
      }
      bst l = Bst(root->left); // left sub-tree
      bst r = Bst(root->right); // right sub-tree

      bst ans;

      ans.max = max(root->val, max(l.max, r.max));
      ans.min = min(root->val, min(l.min, r.min));

      // Check if current tree is Bst or not ?
      ans.isbst = l.isbst && r.isbst && (l.max < root->val && r.min > root->val);

      if(ans.isbst){
          ans.sum = l.sum + r.sum + root->val;
          ans.min = min(root->val, min(l.min, r.min));
          ans.max = max(root->val, max(l.max, r.max));
      }
      else
          ans.sum = max(l.sum, r.sum);
      
      res = max(res, ans.sum);
      return ans;
    }
    
    int res = INT_MIN;
    int maxSumBST(TreeNode* root) {
        Bst(root);
        return res > 0 ? res : 0;
    }
};