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
//     string s="";
//     bool ispalindrome(string s)
//     {
//         int i=0,j=s.size()-1;
//         while(i<j)
//         {
//             if(s[i++]!=s[j--]) return false;
//         }
//         return true;
//     }
//     void dfs(TreeNode*root,int &ans)
//     {
//         if(!root) return ;
//         s+=to_string(root->val);
//         if(!root->left && !root->right)
//         {
//             if(ispalindrome(s))ans++;
            
//         }
//         dfs(root->left,ans);
//         dfs(root->right,ans);
//         s.pop_back();
//      }
    void dfs(TreeNode*root,int &ans,set<int>st)
    {
        if(!root) return ;
        if(st.find(root->val)!=st.end()) 
            st.erase(root->val);
        else 
            st.insert(root->val);
        if(!root->left && !root->right)
        {
            if(st.size()<=1) ans++;
            return;
        }
        if(root->left) dfs(root->left,ans,st);
        if(root->right) dfs(root->right,ans,st);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        if(!root) return ans;
        set<int>st;
        dfs(root,ans,st);
        return ans;
    }
};