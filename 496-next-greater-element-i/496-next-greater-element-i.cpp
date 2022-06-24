class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector<int>ans;
        stack<int>st;
        map<int,int>m;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
                m[nums2[i]]=-1;
            }
            else if(st.top()>nums2[i])
            {
                m[nums2[i]]=st.top();
            }
            else if(st.size()>0 && st.top()<nums2[i])
            {
                while(!st.empty()&&st.top()<nums2[i])
                {
                    st.pop();
                }
                if(st.empty())
                    m[nums2[i]]=-1;
                else m[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        for(auto &i:nums1)
            ans.push_back(m[i]);
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//        vector<int>ans;
//         stack<int>st;
//         map<int,int>m;
//         for(int i=nums2.size()-1;i>=0;i--)
//         {
//             while(!st.empty()&&st.top()<nums2[i])
//                 st.pop();
            
//             if(st.empty())
//                 m[nums2[i]]=-1;
//             else 
//                 m[nums2[i]]=st.top();
            
//             st.push(nums2[i]);   
//         }
//         for(auto &i:nums1)
//         {
//             ans.push_back(m[i]);
//         }
//         return ans ;
//     }
// };




// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
//         vector<int>out;
//         for(int i=0;i<nums1.size();i++)
//         {
//             for(int j=0;j<nums2.size();j++)
//             {
//                 if(nums1[i]==nums2[j])
//                 {
//                     int max_val=-1;
//                     for(int k=j;k<nums2.size();k++)
//                     {
//                         if(nums2[k]>nums2[j])
//                         {
//                             max_val=nums2[k];
//                             break;
//                         }   
//                     }
//                     out.push_back(max_val);
//                 }
//             }
//         }
//         return out;
        
//     }
// };

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int>ans;
//         for(int i=0;i<nums1.size();i++)
//         {
//             for(int j=0;j<nums2.size();j++)
//             {
//                 if(nums1[i]==nums2[j]){
//                     int tmp=-1;
//                     for(int k=j+1;k<nums2.size();k++)
//                     {
//                         if(nums2[k]>nums2[j])
//                         {
//                             tmp=nums2[k];
//                             break;
//                         }
//                     }
//                     ans.push_back(tmp);
//                 }
//             }
//         }
//          return ans;
//     }
// };