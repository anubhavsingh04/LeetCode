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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,vector<int>>m;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        while(!q.empty())
        {
            int sz=q.size();
            vector<pair<int,int>>v; // node ,y
            for(int i=0;i<sz;i++)
            {
                auto curr=q.front();
                q.pop();
                int y=curr.first;
                TreeNode* node=curr.second;
                v.push_back({node->val,y});
                if(node->left)
                    q.push({y-1,node->left});
                if(node->right)
                    q.push({y+1,node->right});
            }
            sort(v.begin(),v.end());
            for(auto i:v)
            {
                m[i.second].push_back(i.first);
            }
        }
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};