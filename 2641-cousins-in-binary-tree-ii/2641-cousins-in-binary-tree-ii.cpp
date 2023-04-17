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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>>q;
        root->val=0;
        TreeNode*dummy=new TreeNode(-1);
        q.push({root,dummy});
        while(!q.empty())
        {
            int size=q.size();
            map<TreeNode*,vector<TreeNode*>>mp;
            int levelsum=0;
            for(int i=0;i<size;i++)
            {
                auto curr=q.front();
                q.pop();
                TreeNode*node=curr.first;
                TreeNode*par=curr.second;
                mp[par].push_back(node);
                // cout<<node->val<<' '<<par->val<<endl;
                levelsum+=node->val;
                if(node->left) {
                    q.push({node->left,node});
                }
                if(node->right) {
                    q.push({node->right,node});
                }
            }
            // cout<<levelsum<<endl;
            for(auto &i:mp)
            {
                int samechild=0;
                for(auto j:i.second) samechild+=j->val;
                for(auto j:i.second) j->val=levelsum-samechild;
            }
        }
        return root;
    }
};