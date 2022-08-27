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

// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p==NULL||q==NULL) return p==q;
//         return p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
//     }
// };



class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p||!q) return p==q;
        if(p->val!=q->val) return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};




// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p==NULL||q==NULL) return p==q;
//         if(p->val!=q->val) return false;
//         return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
//     }
// };

// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p==NULL||q==NULL) return p==q;
//         queue<TreeNode*>Q;
//         Q.push(p);
//         Q.push(q);
//         while(!Q.empty())
//         {
//             TreeNode*a=Q.front();Q.pop();
//             TreeNode*b=Q.front();Q.pop();
//             if(!a&&!b) continue;
//             if(!a||!b) return false;
//             if(a->val!=b->val) return false;
//             Q.push(a->left);
//             Q.push(b->left);
//             Q.push(a->right);
//             Q.push(b->right);
//         }
//         return true;
//     }
// };