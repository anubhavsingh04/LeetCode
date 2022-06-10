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
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>v;
            for(int i=0;i<sz;i++)
            {
                TreeNode*curr=q.front();
                q.pop();
                
                if(curr->left) 
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                v.push_back(curr->val);
            }
            ans=v[0];
        }
        return ans;
    }
};