class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k--]=nums1[i--];
            }
            else 
            {
                nums1[k--]=nums2[j--];
            }
        }
        while(i>=0)
        {
            nums1[k--]=nums1[i--];
                
        }
        while(j>=0)
        {
            nums1[k--]=nums2[j--];
        }
    }
};







// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i=m-1,j=n-1,k=m+n-1;
//         while(i>=0&&j>=0)
//         {
//             if(nums1[i]>nums2[j])
//             {
//                 nums1[k--]=nums1[i--];
//             }
//             else 
//             {
//                 nums1[k--]=nums2[j--];
//             }
//         }
//         while(i>=0)
//             nums1[k--]=nums1[i--];
//         while(j>=0)
//             nums1[k--]=nums2[j--];
//     }
// };


// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i=0,j=0,k=0;
//         vector<int> temp1(m);
//         vector<int>temp2(n);
//         for(int i=0;i<m;i++)
//         {
//             temp1[i]=nums1[i];
//         }
//         for(int i=0;i<n;i++)
//         {
//             temp2[i]=nums2[i];    
//         }
//         nums1.resize(m+n);
//         while(i<=m-1&&j<=n-1)
//         {
//             if(temp1[i]<temp2[j])
//             {
//                 nums1[k++]=temp1[i++];
//             }
//             else
//             {
//                 nums1[k++]=temp2[j++];
//             }
//         }
//         while(i<=m-1)
//         {
//             nums1[k++]=temp1[i++];
//         }
//         while(j<=n-1)
//         {
//             nums1[k++]=temp2[j++];
//         }
//     }
// };