/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*>q;
        q.push(cloned);
        while(!q.empty())
        {   
            for(int i=0;i<q.size();i++)
            {
                TreeNode*curr=q.front();
                q.pop();
                if(curr->val==target->val)
                {
                    return curr;
                    break;
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
            }
        }
        return nullptr;
    }
};