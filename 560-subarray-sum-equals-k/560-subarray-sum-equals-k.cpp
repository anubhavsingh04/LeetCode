class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0,sum=0;
        unordered_map<int,int>m;
        vector<int>prefix(nums.size()+1,0);
        prefix[0]=0;
        for(int i=0;i<nums.size();i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }
        
        // for(auto i:prefix)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        for(auto i:prefix)
        {
            m[i]++;
        }
        // for(auto i:m) {
        //     cout<<i.first<<" -> "<<i.second<<endl;
        // }
        for(int i=0;i<prefix.size();i++)
        {
            m[prefix[i]]--;
            if(m.find(prefix[i]+k)!=m.end())
                cout<<m[prefix[i]+k]<<" ";
                cnt+=m[prefix[i]+k];
        }
        return cnt;
    }
};



// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int cnt=0,sum=0;
//         unordered_map<int,int>m;
//         for(int i=0;i<nums.size();i++)
//         {
//             sum+=nums[i];
//             if(sum==k) cnt++;
//             if(m.find(sum-k)!=m.end()) cnt++;
//             m[sum]++;
//         }
//         return cnt;
//     }
// };





// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int cnt=0,n=nums.size(),sum=0;
//         unordered_map<int,int>m;
//         m[0]=1;
//         for(auto &i:nums)
//         {
//             sum+=i;
//             cnt+=m[sum-k];
//             m[sum]++;
//         }
//         return cnt;
//     }
// };

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int cnt=0,n=nums.size();
//        vector<int>prefix(n);
//         prefix[0]=nums[0];
//         for(int i=1;i<n;i++)
//         {
//             prefix[i]=prefix[i-1]+nums[i];
//         }
//         // if prefix[i]-prefix[j]==k then from index j+1 to i we have sum=k 
//         unordered_map<int,int>m;
//         for(int i=0;i<n;i++)
//         {
//             if(prefix[i]==k)
//                 cnt++;
//             if(m.find(prefix[i]-k)!=m.end())
//             {
//                 cnt+=m[prefix[i]-k];
//             }
//             m[prefix[i]]++;
//         }
//         return cnt;
//     }
// };


// Brute force gives TLE
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int cnt=0,n=nums.size();
       
//         for(int i=0;i<n;i++)
//         {
//             int sum=0;
//             for(int j=i;j<n;j++)
//             {
//                 sum+=nums[j];
//                 if(sum==k)
//                     cnt++;
//             }
//         }
//         return cnt;
//     }
// };