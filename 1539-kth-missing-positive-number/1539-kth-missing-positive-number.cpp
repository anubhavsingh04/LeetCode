class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int x=1;
        set<int>st(arr.begin(),arr.end());
        vector<int>v;
        while(v.size()<k)
        {
            if(!st.count(x))
            {
                v.push_back(x);
            }
            x++;
        }
        return v[k-1];
    }
};