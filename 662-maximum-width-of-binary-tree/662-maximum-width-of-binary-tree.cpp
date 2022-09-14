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
  
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(!root) return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0}); // 0 based indexing 
        
        while(!q.empty()){
            int sz=q.size();
            int mini=q.front().second;
            int first,last;
            for(int i=0;i<sz;i++)
            {
                int curr_idx=q.front().second-mini; // to avoid overflow and to normalize index 
                TreeNode*curr=q.front().first;
                q.pop();
                
                if(i==0) first=curr_idx;
                if(i==sz-1) last=curr_idx;
                
                if(curr->left){
                    q.push({curr->left,2LL*curr_idx+1});
                }
                if(curr->right){
                    q.push({curr->right,2LL*curr_idx+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};



// 1 based indexing 
// class Solution {
// public:
  
//     int widthOfBinaryTree(TreeNode* root) {
//         queue<pair<TreeNode*,int>>q;
//         int ans=INT_MIN;
//         q.push({root,1});
//         while(!q.empty())
//         {
//             int sz=q.size(),maxi,mini;
//             int min_idx=q.front().second;
//             for(int i=0;i<sz;i++)
//             {
//                 int curr_idx=q.front().second-min_idx+1;
                
//                 TreeNode*curr=q.front().first;
//                 q.pop();
                
//                 if(i==0) {
//                     mini=curr_idx;
//                 }
//                 if(i==sz-1){
//                     maxi=curr_idx;
//                 }
                    
//                 if(curr->left)
//                     q.push({curr->left,2LL*curr_idx});
//                 if(curr->right)
//                     q.push({curr->right,2LL*curr_idx+1});
//             }
//             ans=max(ans,maxi-mini+1);
//         }
//         return ans;
//     }
// };