// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long>v;
        stack<long long>st;
        for(long long i=arr.size()-1;i>=0;i--)
        {
            if(st.empty())
            v.push_back(-1);
            else if(st.top()>arr[i])
            v.push_back(st.top());
            else if(st.size()>0 && st.top()<arr[i])
            {
                while(!st.empty() && st.top()<arr[i])
                st.pop();
                if(st.empty())
                v.push_back(-1);
                else 
                v.push_back(st.top());
            }
            st.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
// credit aditya verma 
// teencondition ho sakti hai for next greater  
// ya to stack khali hoga us case me -1 pus krna hai 
// ya st.top() is greater than nums2[i] us case me ans st.top() hoga 
// ya fir st ka top chota hoga us case me pop krte rehna hai jab tak ki stack empty na ho jaye
// ya fir jab tak stack ka top element nums[i] se chota hai 
// fir check kr lena hai agr while loop stack empty ke vjh se braek hua hai then push -1 otherwise stack ka top greater hone ki vjh se break hua hai is case me push st.top()
// finally reverse the vector in case of nge 

// agr next greater to left hai to left se traverse kro aur vector ko reverse nahi krna hai 
// baki code same hai as of nge
// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends