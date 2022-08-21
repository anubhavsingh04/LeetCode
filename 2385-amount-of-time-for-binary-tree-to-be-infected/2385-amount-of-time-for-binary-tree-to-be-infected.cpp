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

// Make adjacency list from the given tree by level order traversal (in adj matrix we will push {3,5} corresponding to 1 
// and also push 1 corresponding to 3 and 5) we will do repeatedly until adjacency list is formed
// then apply bfs in order to find the min minutes 
// let say we are at 3 which is  start node then in first iteration 3 will be popped and 1,6,10 will be inserted and level becoms 1 
// after 1st iteration 1,6,10 will be popped  and level becomes 2  
// after second iteration 5 will be popped and level will be 3
// after 3rd iteration 4 will be popped  level will 4
// in last iteration 9,2 will be popped and level becimes 5 
// one thing is to be observed here is that in the first iteration we only popped 3 and inserted 1,6,10 and our level becomes 1 this is time 0 since we are not taking any time to infect start node so required time will be 1 less than level so fnally return level-1 as ans 

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        map<int,vector<int>>adj;
        queue<TreeNode*>q; q.push(root);
        // adjacency list formation
        while(!q.empty())
        {
            TreeNode*curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                adj[curr->val].push_back(curr->left->val);
                adj[curr->left->val].push_back(curr->val);
            }
            if(curr->right){
                q.push(curr->right);
                adj[curr->val].push_back(curr->right->val);
                adj[curr->right->val].push_back(curr->val);
            }
        }
        // apply bfs 
        queue<int>q2;
        unordered_set<int>st;
        q2.push(start); st.insert(start);
        int level=0;
        while(!q2.empty())
        {
            int sz=q2.size();
            for(int i=0;i<sz;i++)
            {
                int curr=q2.front();
                q2.pop();
                for(auto &i:adj[curr])
                {
                    if(st.count(i)==0)
                    {
                        q2.push(i);
                        st.insert(i);
                    }
                }
            }
            level++;
        }
        return level-1;
    }
};