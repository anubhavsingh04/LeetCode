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
        queue<pair<TreeNode*,int>>q;
        int ans=INT_MIN;
        q.push({root,1});
        while(!q.empty())
        {
            int sz=q.size(),maxi,mini;
            int min_idx=q.front().second;
            for(int i=0;i<sz;i++)
            {
                int curr_idx=q.front().second-min_idx+1;
                
                TreeNode*curr=q.front().first;
                q.pop();
                
                if(i==0) {
                    mini=curr_idx;
                }
                if(i==sz-1){
                    maxi=curr_idx;
                }
                    
                if(curr->left)
                    q.push({curr->left,2LL*curr_idx});
                if(curr->right)
                    q.push({curr->right,2LL*curr_idx+1});
            }
            ans=max(ans,maxi-mini+1);
        }
        return ans;
    }
};