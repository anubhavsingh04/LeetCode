// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    public:
        stack<int> s1;
        stack<int>s2;
       /*returns min element from stack*/
       int getMin(){
           if(s2.empty())
           return -1;
           return s2.top();
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s1.empty()) return -1;
           int x=s1.top();
           if(s1.top()==s2.top())
           s2.pop();
           s1.pop();
           return x;
       }
       
       /*push element x into the stack*/
       void push(int x){
           s1.push(x);
           if(s2.empty()||s1.top()<=s2.top())
           s2.push(x);
       }
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends