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
// Node is covered --> return 1
// child ko cammera nahi chahiye aur cammera bhi nahi hai--> return 0
// Node needs cammera --> return -1


class Solution {
public:
    int ans = 0;
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==-1) ans++;
        return ans;
    }
    int dfs(TreeNode* root) {
        if (!root) return 1; // covered hai 
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==-1||right==-1)
        {
            ans++;
            return 0; // have cammera node told to his parent  
        }
        if(left==0||right==0) return 1; // dono child ke pas cammera nahi hai 
                                          // aur cammera bhi nahi chahiye
        return -1;    // then parent bolega mughe mera parent dekhega -->credit pepcoding
    }
};





// class Solution {
// public:
//     int ans = 0;
//     int minCameraCover(TreeNode* root) {
//         return dfs(root) > 2 ? ans + 1 : ans;
//     }
//     int dfs(TreeNode* node) {
//         if (!node) return 0;
//         int val = dfs(node->left) + dfs(node->right);
//         if (val == 0) return 3;
//         if (val < 3) return 0;
//         ans++;
//         return 1;
//     }
// };
