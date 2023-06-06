class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int>st;
        int maxi=INT_MIN,mini=INT_MAX;
        for(auto &i:arr)
        {
            maxi=max(maxi,i);
            mini=min(mini,i);
            st.insert(i);
        }
        if((maxi-mini)%(n-1)!=0) return false;
        int d=(maxi-mini)/(n-1);
    
        while(n--)
        {
            if(!st.count(mini)) return false;
            mini+=d;
        }
        return true;
    }
};