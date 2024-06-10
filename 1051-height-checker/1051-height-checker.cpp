class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>v=heights;
        int ans=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(heights[i]!=v[i]) ans++;
        }
        return ans;
    }
};