class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int size=(rolls.size()+n);
        int sum_left=(mean*size-accumulate(rolls.begin(),rolls.end(),0));
        // sum must lie b/w n to 6*n
        vector<int>ans(n,sum_left/n); // divide sum into n equal parts 
        if(sum_left<n||sum_left>6*n) return {};
        int rem=sum_left%n;
        // add 1 to each ans[i] until remainder is zero
        int i=0;
        while(rem--)
        {
            ans[i]+=1;
            i++;
        }
        return ans;
    }
};