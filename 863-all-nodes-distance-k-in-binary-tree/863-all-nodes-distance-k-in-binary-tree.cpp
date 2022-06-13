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
	void markparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m)
	{
		queue<TreeNode*>q;
		q.push(root);
		while(!q.empty()){
			int sz=q.size();
			for(int i=0;i<sz;i++)
			{
				TreeNode*curr=q.front(); q.pop();
				if(curr->left)
				{
					m[curr->left]=curr;
					q.push(curr->left);
				}
				if(curr->right)
				{
					m[curr->right]=curr;
					q.push(curr->right);
				}
			}
		}
	}
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

		unordered_map<TreeNode*,TreeNode*>m; // to keep track of parents 
		markparent(root,m);
		unordered_map<TreeNode*,bool>vis;
		int level=0;
		queue<TreeNode*>q;
		q.push(target);
		vis[target]=true;
		while(!q.empty())
		{
			int sz=q.size();

			if(level==k)  // level is distance from target node 
				break;
			else 
				level++; // for each level increase the level

			for(int i=0;i<sz;i++)
			{
				TreeNode*curr=q.front();
				q.pop();
				if(curr->left&&!vis[curr->left]) // if left exist and not visited 
				{
					q.push(curr->left);
					vis[curr->left]=true;   // mark as visited 
				}
				if(curr->right&&!vis[curr->right]) // if right child exist and not visited 
				{
					q.push(curr->right);
					vis[curr->right]=true;  // mark as visited 
				}
				if(m[curr]&&!vis[m[curr]]) // if parent of curr node exist and not visited 
				{
					q.push(m[curr]);
					vis[m[curr]]=true;   // mark as visited 
				}
			}
		}
		vector<int>ans;
		while(!q.empty())
		{
			TreeNode*curr=q.front();
			q.pop();
			ans.push_back(curr->val);
		}
		return ans;
	}
};