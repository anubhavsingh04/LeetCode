class Solution {
public:
    bool unique(string &s)
    {
        set<char>st;
        for(auto &ch:s)
        {
            if(st.count(ch)) return false;
            st.insert(ch);
        }
        return true;
    }
    void rec(string s,int idx,vector<string>&arr,int n,int &ans)
    {
        if(!unique(s)) return;
        int sz=s.size();
        ans=max(ans,sz);
        
        if(idx>=n) return ;
        
        rec(s+arr[idx],idx+1,arr,n,ans); // take 
        rec(s,idx+1,arr,n,ans); // not take
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size(),ans=0;
        rec("",0,arr,n,ans);
        return ans;
    }
};