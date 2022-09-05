/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>v;
            for(int i=0;i<sz;i++)
            {
                Node*curr=q.front();
                q.pop();
                if(!curr) continue;
                v.push_back(curr->val);
                for(auto j:curr->children)
                    q.push(j);
            }
            ans.push_back(v);
        }
        return ans;
    }
};