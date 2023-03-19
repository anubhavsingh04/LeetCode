//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        vector<int>pfs(N),suf(N);
        set<int>st;
        pfs[0]=0;
        suf[N-1]=0;
        st.insert(A[0]);
        for(int i=1;i<N;i++)
        {
            pfs[i]=st.size();
            st.insert(A[i]);
        }
        st.clear();
        st.insert(A[N-1]);
        for(int i=N-2;i>=0;i--)
        {
            suf[i]=st.size();
            st.insert(A[i]);
        }
        vector<int>ans(N);
        for(int i=0;i<N;i++)
        {
            ans[i]=pfs[i]-suf[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends