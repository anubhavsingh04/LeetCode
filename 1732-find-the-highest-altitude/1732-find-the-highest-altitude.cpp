class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        vector<int>h(gain.size()+1);
        h[0]=0;
        for(int i=0;i<gain.size();i++)
        {
            h[i+1]=h[i]+gain[i];
        }
        return *max_element(h.begin(),h.end());
    }
};