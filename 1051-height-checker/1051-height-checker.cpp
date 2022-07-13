class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>tmp=heights;
        sort(heights.begin(),heights.end());
        int cnt=0;
        for(int i=0;i<heights.size();i++)
        {
            if(tmp[i]!=heights[i])
                cnt++;
        }
        return cnt;
    }
};