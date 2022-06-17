/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// using levelorder and stringstream getline(s,str,',') means 
// s pe iterate krna hai chracter by  character with seprator ,

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root) return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*curr=q.front();
            q.pop();
            if(curr==NULL)
            {
                s+="#,";
            }
            else {
                s+=(to_string(curr->val)+',');
            }
            if(curr!=NULL)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        
        stringstream s(data);
        string str;
        getline(s,str,',');
        
        TreeNode*root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode*curr=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
            {
                curr->left=NULL;
            }
            else
            {
                TreeNode*leftnode=new TreeNode(stoi(str));
                curr->left=leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str=="#")
            {
                curr->right=NULL;
            }
            else {
                TreeNode*rightnode=new TreeNode(stoi(str));
                curr->right=rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};





// using preorder 
// class Codec {
// public:
//     TreeNode* maketree(queue<string>&q)
//     {
//         string s=q.front();
//         q.pop();
//         if(s=="null")
//             return NULL;
        
//         TreeNode* root=new TreeNode(stoi(s));
//         root->left=maketree(q);
//         root->right=maketree(q);
//         return root;
//     }
//     // Encodes a tree to a single string.
    
//     string serialize(TreeNode* root) {
//         if(!root) return "null,";
//         return to_string(root->val)+","+ serialize(root->left) + serialize(root->right);
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         string s;
//         queue<string>q;
//         for(int i=0;i<data.size();i++)
//         {
//             if(data[i]==',')
//             {
//                 q.push(s);
//                 s="";
//                 continue;
//             }
//             s+=data[i];
//         }
//         // if(s.size()!=0) q.push(s);
//         return maketree(q);
//     }
// };

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));