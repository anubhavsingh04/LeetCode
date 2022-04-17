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
        vector<int> nodes;
public:
    void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        nodes.push_back(root->val);
        inOrder(root->right);
        
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* new_head = new TreeNode();
        TreeNode* curr = new_head;
        inOrder(root);
        for (auto a : nodes) {
            curr->right = new TreeNode(a);
            curr = curr->right;
        }
        return new_head->right;
    }
};