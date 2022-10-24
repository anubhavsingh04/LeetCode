class Solution {
public:
    int ans=0;
     bool unique(string str)
    {
        set<char>st;
        for(auto ch:str)
        {
            if(st.find(ch)!=st.end()) return false;
            st.insert(ch);
        }
        return true;
    }
    void rec(string s,vector<string>&arr,int idx)
    {
        if(!unique(s)) return;
        int sz=s.size();
        ans=max(ans,sz);
        for(int i=idx;i<arr.size();i++)
        {
            rec(s+arr[i],arr,i+1);
        }
    }
    int maxLength(vector<string>& arr) {
        rec("",arr,0);
        return ans;
    }
};
