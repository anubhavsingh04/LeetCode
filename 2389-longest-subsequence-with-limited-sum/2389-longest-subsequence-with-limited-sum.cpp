// TC: O(nlogn) SC: O(n)
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m=queries.size();
        vector<int>ans;
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<m;i++)
        {
            int query=queries[i];
            ans.push_back(upper_bound(prefix.begin(),prefix.end(),query)-prefix.begin());
        }
        return ans;
    }
};



// Bruteforce TC: O(nlog(n)+n*m)==>O(n*m) 
// class Solution {
// public:
//     vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
//         sort(nums.begin(),nums.end());
//         vector<int>ans(queries.size());
//         for(int i=0;i<queries.size();i++)
//         {
//             int sum=0;
//             int cnt=0;
//             for(int j=0;j<nums.size();j++)
//             {
//                 if(sum+nums[j]<=queries[i])
//                 {
//                     sum+=nums[j];
//                     cnt++;
//                 }
//             }
//             ans[i]=cnt;
//         }
//         return ans;
//     }
// };


