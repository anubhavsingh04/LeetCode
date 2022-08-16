/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>mat(m,vector<int>(n,-1));
        int i=0,j=0;
        while(head!=NULL)
        {
            if(j<n)
            {
                while(head!=NULL && j<n && mat[i][j]==-1)
                {
                    mat[i][j]=head->val;
                    head=head->next;
                    j++;
                }
                if(head==NULL) break;
                i++;
                j--;
            }
            if(i<m)
            {
                while(head!=NULL && i<m && mat[i][j]==-1)
                {
                    mat[i][j]=head->val;
                    head=head->next;
                    i++;
                }
                // if(head==NULL) break;
                i--;
                j--;
            }
            if(j>=0)
            {
                while(head!=NULL && j>=0 && mat[i][j]==-1)
                {
                    mat[i][j]=head->val;
                    head=head->next;
                    j--;
                }
                // if(head==NULL) break;
                j++;
                i--;
            }
            if(i>=0)
            {
                while(head!=NULL && i>=0 && mat[i][j]==-1)
                {
                    mat[i][j]=head->val;
                    head=head->next;
                    i--;
                }
                // if(head==NULL) break;
                i++;
                j++;
            }
            // n++;
            // m--;
        }
        return mat;
    }
};

