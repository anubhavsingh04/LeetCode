/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// agar kisi point pe hame p ya q milega to p or return karna hai if not found return null
// in case agr kisi node pe hame p aur q dono return ho rhe hai us case me root ki hi value return 
// kro and that value will also be lowest common ancestor

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q)
            return root;
        TreeNode*lft=lowestCommonAncestor(root->left,p,q);
        TreeNode*rt=lowestCommonAncestor(root->right,p,q);
        
        if(lft==NULL)
            return rt;
        else if(rt==NULL)
            return lft;
            else // is case me p aur q dono return ho rhe hain and none of them are nULL
                return root;
    }
};