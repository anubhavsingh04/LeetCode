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
    string ans="";
    void help(TreeNode* root ,string s)
    {
        
    if(!root) return;
        s=(char)(root->val+97)+s;
        if(root->left==NULL and root->right==NULL )
        {
            if(ans.empty()) 
                ans=s;
            else 
                ans=min(ans,s);
        }
        
        help(root->left,s);
        help(root->right,s);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        help(root,"");
        return ans;
    }
};


// class Solution {
// public:
//     string s;
//     void help(TreeNode* root ,vector<string>&v)
//     {
        
//     if(!root)
//         return;
//         s.push_back(root->val+97);
//         if(root->left==NULL and root->right==NULL )
//         {
//             string tmp=s;
//             reverse(tmp.begin(),tmp.end());
//             v.push_back(tmp);
//         }
        
//         help(root->left,v);
//         help(root->right,v);
//         s.pop_back();
//     }
//     string smallestFromLeaf(TreeNode* root) {
//         vector<string>v;
//         help(root,v);
//         sort(v.begin(),v.end());
//         return v[0];
      
//     }
// };