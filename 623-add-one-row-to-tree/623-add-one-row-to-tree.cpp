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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode*newnode=new TreeNode(val);
            newnode->left=root;
            return newnode;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode*curr=q.front(); 
                q.pop();
                if(level!=depth-1)
                {
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                else
                {
                    TreeNode*node1=new TreeNode(val);
                    TreeNode*node2=new TreeNode(val);
                    node1->left=curr->left;
                    curr->left=node1;
                    node2->right=curr->right;
                    curr->right=node2;
                }
            }
            level++;
        }
        return root;
    }
};