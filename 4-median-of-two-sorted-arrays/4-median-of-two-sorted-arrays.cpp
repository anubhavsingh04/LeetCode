class Solution {
public:
    vector<int>merge(vector<int>&nums1,vector<int>&nums2,int n,int m)
    {
        vector<int>ans;
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<m)
        {
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>v=merge(nums1,nums2,n,m);
        int size=v.size();

        if(size&1) 
            return v[size/2];
        else 
            return (v[size/2]+v[size/2-1])/(double)2;
        // return median;
    }
};




// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//     int m = nums2.size();
//     if (n > m)
//         return findMedianSortedArrays(nums2, nums1); // Swapping to make A smaller
 
//     int start = 0;
//     int end = n;
//     int realmidinmergedarray = (n + m + 1) / 2;
 
//     while (start <= end) {
//         int mid = (start + end) / 2;
//         int leftAsize = mid;
//         int leftBsize = realmidinmergedarray - mid;
//         int leftA
//             = (leftAsize > 0)
//                   ? nums1[leftAsize - 1]
//                   : INT_MIN; // checking overflow of indices
//         int leftB
//             = (leftBsize > 0) ? nums2[leftBsize - 1] : INT_MIN;
//         int rightA
//             = (leftAsize < n) ? nums1[leftAsize] : INT_MAX;
//         int rightB
//             = (leftBsize < m) ? nums2[leftBsize] : INT_MAX;
 
//         // if correct partition is done
//         if (leftA <= rightB and leftB <= rightA) {
//             if ((m + n) % 2 == 0)
//                 return (max(leftA, leftB)
//                         + min(rightA, rightB))
//                        / 2.0;
//             return max(leftA, leftB);
//         }
//         else if (leftA > rightB) {
//             end = mid - 1;
//         }
//         else
//             start = mid + 1;
//     }
//     return 0.0;
//     }
// };