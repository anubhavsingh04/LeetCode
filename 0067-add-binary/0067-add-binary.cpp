class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size()-1;
        int m=b.size()-1;
        string ans="";
        int carry=0;
        while(n>=0||m>=0||carry)
        {
            int cnt=0;
            if(n>=0)
            {
                cnt+=(a[n]=='1');
                n--;
            }
            if(m>=0)
            {
                cnt+=(b[m]=='1');
                m--;
            }
            cnt+=(carry==1);
            ans+=to_string(cnt%2);
            carry=cnt/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};