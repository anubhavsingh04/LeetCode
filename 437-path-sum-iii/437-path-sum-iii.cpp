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
    int ans=0;
    unordered_map<long long,int>m;
    void dfs(TreeNode*root,int &target,long long sum)
    {
        if(!root) return;
        sum+=root->val;
        if(sum==target) ans++;
        if(m.find(sum-target)!=m.end())
        {
            ans+=m[sum-target];
        }
        m[sum]++;
        dfs(root->left,target,sum);
        dfs(root->right,target,sum);
        m[sum]--;
        
    }
    int pathSum(TreeNode* root, int target) {
        if(!root) return 0;
        dfs(root,target,0LL);
        return ans;
    }
};