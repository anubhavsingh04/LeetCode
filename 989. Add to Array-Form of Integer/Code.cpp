class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        int i=num.size()-1;
        int carry=0;
        while(carry>0||k>0||i>=0)
        {
            if(k>0)
            {
                carry+=k%10;
                k/=10;
            }
            if(i>=0)
            {
                carry+=num[i];
                i--;
            }
            ans.push_back(carry%10);
            carry/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};