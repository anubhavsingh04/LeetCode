class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>st;
        for(auto &i:nums){
            while(!st.empty()){
                int top=st.back();
                int hcf=__gcd(i,top);
                if(hcf==1) break;
                st.pop_back();
                long long merge=(long long)top/hcf*i;
                i=(int) merge;
            }
            st.push_back(i); 
        }
        return st;
    }
};