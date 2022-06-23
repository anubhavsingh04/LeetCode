class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n&1)
        {
            ans.push_back(0);
            n--;
        }
        
        while(n)
        {
            ans.push_back(n);
            ans.push_back(-1*n);
            n-=2;
        }
        return ans;
    }
};