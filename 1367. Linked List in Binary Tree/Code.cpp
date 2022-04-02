class Solution {
public:
    bool dfs(TreeNode* root, ListNode* head){
        if(head==NULL) return true;
        if(root==NULL || root->val!=head->val) 
            return false;
        return dfs(root->left, head->next) || dfs(root->right, head->next);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head==NULL) 
            return false;
        if(root==NULL)
            return false;
        if(dfs(root, head))
            return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};