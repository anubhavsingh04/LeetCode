// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         // map<int,int>m;
//         sort(nums.begin(),nums.end());
//         vector<vector<int>>ans;
//         set<vector<int>>st;
//         int n=nums.size();
//         // for(auto &i:nums)
//         // {
//         //     m[i]++;
//         // }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 long long newtarget=(long long)target-nums[i]-nums[j];
//                 int x=j+1,y=n-1;
//                 while(x<y)
//                 {
//                     int sum=nums[x]+nums[y];
//                     if(sum==newtarget)
//                     {
//                         st.insert({nums[i],nums[j],nums[x],nums[y]});
//                         x++,y--;
//                     }
//                     else if(sum<newtarget) x++;
//                     else y--;
//                 }
//             }
//         }
//         for(auto &i:st)
//         {
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long long newtarget=(long long)target-nums[i]-nums[j];
                int x=j+1,y=n-1;
                while(x<y)
                {
                    int sum=nums[x]+nums[y];
                    if(sum==newtarget)
                    {
                        vector<int>squad(4,0);
                        squad[0]=nums[i];
                        squad[1]=nums[j];
                        squad[2]=nums[x];
                        squad[3]=nums[y];
                        st.insert(squad);
                        x++,y--;
                        
                        while(x<y && nums[x]==squad[2]) x++;
                        while(x<y && nums[y]==squad[3]) y--;
                    }
                    else if(sum<newtarget) x++;
                    else y--;
                }
            }
        }
        for(auto &i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};


// Three pointer + Binary search 
// start i from 0 j from i+1 and k from j+1 and for fourth element(target-nums[i]-nums[j]-nums[k]) do binarysearch and 
// store all the 4 element as vector inside the set if the 4rth element is found 
// otherwise k will be increased 

// class Solution {
// public:
    
//     int binarySearch(vector<int>&nums,int element,int start,int end)
//     {
//         int lo=start,hi=end-1;
//         while(lo<=hi)
//         {
//             int mid=(lo+(hi-lo)/2);
//             if(nums[mid]==element) return mid;
//             else if(nums[mid]<element) lo++;
//             else hi--;
//         }
//         return -1;
//     }
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         vector<vector<int>>ans;
//         set<vector<int>>st;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 for(int k=j+1;k<n;k++)
//                 {
//                     long long element=(long long)target-nums[i]-nums[j]-nums[k];
//                     int start=k+1,end=n;
//                     if(binarySearch(nums,element,start,end)!=-1)
//                     {
//                         st.insert({nums[i],nums[j],nums[k],element});
//                     }
//                 }
//             }
//         }
//         for(auto &i:st)
//         {
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };

