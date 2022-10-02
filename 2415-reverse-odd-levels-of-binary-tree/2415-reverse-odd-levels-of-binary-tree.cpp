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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level=0;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>tmp;
            for(int i=0;i<size;i++)
            {
                TreeNode*curr=q.front();
                q.pop();
                if(level&1)
                {
                    curr->val=v[size-i-1];
                }
                if(curr->left) {
                    q.push(curr->left);
                    tmp.push_back(curr->left->val);
                }
                if(curr->right) {
                    q.push(curr->right);
                    tmp.push_back(curr->right->val);
                }
            }
            level++;
            v=tmp;
        }
        return root;
    }
};