// since size of all three nums<=100
// make a vector of vector of size 101

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<vector<bool>>v(3,vector<bool>(101,false));
        vector<int>ans;
        for(auto &i:nums1)
        {
            v[0][i]=true;
        }
        for(auto &i:nums2)
        {
            v[1][i]=true;
        }
        for(auto &i:nums3)
        {
            v[2][i]=true;
        }
        for(int i=1;i<=100;i++)
        {
            if(v[0][i]+v[1][i]+v[2][i]>1)
                ans.push_back(i);
        }
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
//         vector<int>ans;
//         unordered_map<int,unordered_set<int>>m;
//         for(auto &i:nums1)
//         {
//             m[i].insert(1);
//         }
//         for(auto &i:nums2)
//         {
//             m[i].insert(2);
//         }
//         for(auto &i:nums3)
//         {
//             m[i].insert(3);
//         }
//         for(auto &i:m)
//         {
//             if(i.second.size()>=2)
//                 ans.push_back(i.first);
//         }
//         return ans;
//     }
// };