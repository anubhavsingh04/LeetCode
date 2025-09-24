class Solution {
public:
    string fractionToDecimal(int a, int b) {
        if(a==0) return "0";
        string ans="";
        ans= (a<0)^(b<0) ? "-":"";
        long x=labs(a);
        long y=labs(b);
        ans+=to_string(x/y);
        long rem=x%y;
        if(rem==0) return ans;
        ans+=".";
        unordered_map<int,int>mp;
        while(rem!=0){
            if(mp.find(rem)!=mp.end()){
                ans.insert(mp[rem],"(");
                ans+=")";
                return ans;
            }
            else{
                mp[rem]=ans.size();
                rem*=10;
                ans+=to_string(rem/y);
                rem=rem%y;
            }
        }
        return ans;
    }
};