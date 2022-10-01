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
        map<int,vector<int>>m; // y, node values in sorted order 
        queue<pair<int,TreeNode*>>q; // y,Node
        q.push({0,root});
        while(!q.empty())
        {
            int size=q.size();
            vector<pair<int,int>>v; // nodevalue , y (for the purpose of pushing in map first sort then push)
            for(int i=0;i<size;i++)
            {
                auto curr=q.front(); 
                q.pop();
                int y=curr.first;
                TreeNode*node=curr.second;
                v.push_back({node->val,y});
                if(node->left) q.push({y-1,node->left});
                if(node->right) q.push({y+1,node->right});
            }
            sort(v.begin(),v.end());
            for(auto i:v)
            {
                m[i.second].push_back(i.first);
            }
        }
        vector<vector<int>>ans;
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};