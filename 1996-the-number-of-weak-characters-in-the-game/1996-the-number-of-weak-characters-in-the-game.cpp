class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        int maxdefence=INT_MIN;
        for(int i=0;i<v.size();i++)
        {
            if(maxdefence>v[i][1])
            {
                ans++;
            }
            else 
            {
                maxdefence=v[i][1];
            }
        }
        return ans;
    }
};