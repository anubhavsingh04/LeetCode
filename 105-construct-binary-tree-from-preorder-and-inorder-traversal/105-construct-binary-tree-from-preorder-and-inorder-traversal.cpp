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


// left ke liye inorder instart sestart hoga aur pos-1 tak chalega
// right ke liye inorder pos+1 se start hoga aur inend tak jayega
// left ke liye preorder prestart+1 se start hoga aur prestart=numleft tak jayega 
// (numleft=left me kitne no haii)
// right ke liye preorder prestart+numsleft+1 se leke preend tak jayega


class Solution {
public:
    TreeNode* solve(vector<int>&inorder,int instart,int inend,
                    vector<int>&preorder,int prestart,int preend,unordered_map<int,int>&inMap)
    {
        if(instart>inend||prestart>preend)
            return nullptr;
        
        TreeNode*root=new TreeNode(preorder[prestart]);
        int pos=inMap[root->val]; // this position indicates root ki val inorder me kaha lie kr rhi h
        int numleft=pos-instart;
        root->left=solve(inorder,instart,pos-1,preorder,prestart+1,prestart+numleft,inMap);
        root->right=solve(inorder,pos+1,inend,preorder,prestart+numleft+1,preend,inMap);
        return root;
    }
        
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        unordered_map<int,int>inMap;
        for(int i=0;i<inorder.size();i++)
        {
            inMap[inorder[i]]=i;
        }
        return solve(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,inMap);
    }
    
};




// class Solution {
// public:
//      TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int instart,
//                      int inend,int &preindex,unordered_map<int,int>&m)
//      {
//          if(instart>inend)
//              return NULL;
//          TreeNode*root=new TreeNode(preorder[preindex++]);
//          int pos=m[root->val];
//          root->left=solve(preorder,inorder,instart,pos-1,preindex,m);
//          root->right=solve(preorder,inorder,pos+1,inend,preindex,m);
//          return root;
//      }
//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
//         unordered_map<int,int>m;
//         for(int i=0;i<inorder.size();i++)
//         {
//             m[inorder[i]]=i;
//         }
//         int preindex=0;
//         return solve(preorder,inorder,0,inorder.size()-1,preindex,m);
//     }
    
// };






// class Solution {
// public:
//     int find(vector<int>&inorder,int element)
//     {
//         for(int i=0;i<inorder.size();i++)
//         {
//             if(inorder[i]==element)
//             return i;
//         }
//         return -1;
//     }
//      TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int &preindex,int instart,
//                      int inend,int n)      {
//          if(instart>inend||preindex>n){
//              return NULL;
//          }
//          int curr=preorder[preindex++];
//          TreeNode*root=new TreeNode(curr);
//          int pos=find(inorder,curr);
         
//          root->left=solve(preorder,inorder,preindex,instart,pos-1,n);
//          root->right=solve(preorder,inorder,preindex,pos+1,inend,n);
//          return root;
//      }
//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        
//         int preindex=0;
//         return solve(preorder,inorder,preindex,0,inorder.size()-1,preorder.size()-1);
//     }
    
// };





// class Solution {
// public:
//     int preInd=0;
//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
//         return createTree(preorder,inorder,0,inorder.size() - 1);
//     }
//     TreeNode* createTree(vector<int>& preorder, vector<int>& inorder,int start, int end){
//         if(start > end){
//             return NULL;
//         }
//         TreeNode* node=new TreeNode(preorder[preInd++]);
//         int pos;
//         for(int i=start;i<=end;i++){
//             if(inorder[i]==node->val){
//                 pos=i;
//                 break;
//             }
//         }
//         node->left =createTree(preorder, inorder,start,pos-1);
//         node->right =createTree(preorder, inorder, pos+1,end);
//         return node;
//     }
// };
