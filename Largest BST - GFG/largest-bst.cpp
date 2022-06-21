// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// gfg me TreeNode* ke jagah Node* hai aur root->val ke jagah root->data hai
class nodevalue{
    public:
    int minval,maxval,maxsize;
    nodevalue(int minval,int maxval,int maxsize)
    {
        this->minval=minval;
        this->maxval=maxval;
        this->maxsize=maxsize;
        
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    nodevalue largestbsthelper(Node*root)
    {
        // just like post order traversal 
        if(!root) return nodevalue(INT_MAX,INT_MIN,0);
        auto left=largestbsthelper(root->left);
        auto right=largestbsthelper(root->right);
        // here we will do all thing with root 
        // if the current node is greater than minimum data of left 
        // and smaller than max data of right then it is a bst
        if(root->data>left.maxval && root->data<right.minval)
        {
            return nodevalue(min(root->data,left.minval),max(root->data,right.maxval),
            left.maxsize+right.maxsize+1);
        }
        // otherwise return -inf ,inf so that parent can be a bst
        return nodevalue(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize));
    }
    int largestBst(Node *root)
    {
    	return largestbsthelper(root).maxsize;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends