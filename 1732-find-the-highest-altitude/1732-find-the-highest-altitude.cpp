class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr_h=0,max_h=0;
        for(int i=0;i<gain.size();i++)
        {
            curr_h+=gain[i];
            max_h=max(max_h,curr_h);
        }
        return max_h;
    }
};




// class Solution {
// public:
//     int largestAltitude(vector<int>& gain) {
//         int ans=0;
//         vector<int>h(gain.size()+1);
//         h[0]=0;
//         for(int i=0;i<gain.size();i++)
//         {
//             h[i+1]=h[i]+gain[i];
//         }
//         return *max_element(h.begin(),h.end());
//     }
// };