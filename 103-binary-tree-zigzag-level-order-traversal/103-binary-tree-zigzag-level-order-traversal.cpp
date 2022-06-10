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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root); 
        bool flag=1; // means left to right  ans flag 0 means right to left
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>level(sz);
            for(int i=0;i<sz;i++)
            {
                TreeNode*curr=q.front();
                q.pop();
                int index=(flag==1?i:sz-1-i);
                level[index]=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(level);
            flag=!flag;
        }
        return ans ;
    }
};