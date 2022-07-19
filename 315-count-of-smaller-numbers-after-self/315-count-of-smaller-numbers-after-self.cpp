class Solution {
public:
    void merge(vector<pair<int,int>>&nums,int s,int mid,int e,vector<int>&ans)
    {
        vector<pair<int,int>>tmp(e-s+1);
        int i=s,j=mid,k=0,invcnt=0;
        while(i<=mid-1 && j<=e)
        {
            if(nums[i].first<=nums[j].first)
            {
                ans[nums[i].second]+=invcnt;
                tmp[k++]=nums[i++];
            }
            else
            {
                invcnt++;
                tmp[k++]=nums[j++];
            }
        }
        while(i<=mid-1)
        {
            ans[nums[i].second]+=invcnt;
            tmp[k++]=nums[i++];
        }
        while(j<=e)
        {
            tmp[k++]=nums[j++];
        }
        i=s,k=0;
        while(i<=e)
        {
            nums[i++]=tmp[k++];
        }
    }
    void mergesort(vector<pair<int,int>>&nums,int s,int e,vector<int>&ans)
    {
        if(s>=e) return;
        int mid=(s+e)/2;
        mergesort(nums,s,mid,ans);
        mergesort(nums,mid+1,e,ans);
        merge(nums,s,mid+1,e,ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>>arr(nums.size());
        
        for(int i=0;i<nums.size();i++)
        {
            arr[i]={nums[i],i};
        }
        vector<int>ans(nums.size(),0);
        mergesort(arr,0,nums.size()-1,ans);
        return ans;
    }
};



// class Solution {
// public:
//     void merge(vector<pair<int, int>>& nums, int s, int mid, int e, vector<int> &ans){
//         vector<pair<int, int>> sortedArray(e - s + 1);
        
//         int i = s;
//         int j = mid + 1;
//         int k = 0;
//         int smallerOnRight = 0;
        
//         while(i <= mid and j <= e){
//             if(nums[i].first <= nums[j].first){
//                 ans[nums[i].second] += smallerOnRight;
//                 sortedArray[k] = nums[i];
//                 i++; k++;
//             } else {
//                 smallerOnRight++;
//                 sortedArray[k] = nums[j];
//                 j++; k++;
//             }
//         }
        
//         while(i <= mid){
//             ans[nums[i].second] += smallerOnRight;
//             sortedArray[k] = nums[i];
//             i++; k++;
//         }
        
//         while(j <= e){
//             sortedArray[k] = nums[j];
//             j++; k++;
//         }
        
//         k=0;
//         i=s;
//         while(i<=e)
//         {
//             nums[i++]=sortedArray[k++];
//         }
//     }
    
//     void mergeSort(vector<pair<int, int>>& nums, int s, int e, vector<int> &ans){
//         if(s >= e){
//             return;
//         }
        
//         int mid = s + (e - s) / 2;
        
//         mergeSort(nums, s, mid, ans);
//         mergeSort(nums, mid + 1, e, ans);
        
//         merge(nums, s, mid, e, ans);
//     }
    
    
//     vector<int> countSmaller(vector<int>& nums) {
//         vector<pair<int, int>> arr(nums.size());
//         for(int i = 0; i < nums.size(); i++){
//             arr[i] = {nums[i], i};
//         }
        
//         vector<int> ans(nums.size(), 0);
        
//         mergeSort(arr, 0, nums.size()-1, ans);
        
//         return ans;
//     }
// };