class Solution {
public:
    int merge(vector<int>&nums,int start,int mid ,int end)
    {
        int cnt=0;
        int j=mid+1;
        for(int i=start;i<=mid;i++)
        {
            while(j<=end && nums[i]>2LL*nums[j])
            {
                j++;
            }
            cnt+=j-(mid+1);
        }
        int left=start,right=mid+1;
        vector<int>tmp;
        while(left<=mid && right<=end)
        {
            if(nums[left]<=nums[right])
                tmp.push_back(nums[left++]);
            else
                tmp.push_back(nums[right++]);
        }
        while(left<=mid)
            tmp.push_back(nums[left++]);
        while(right<=end)
            tmp.push_back(nums[right++]);
        for(int i=start;i<=end;i++)
            nums[i]=tmp[i-start];
        return cnt;
    }
    int mergesort(vector<int>&nums,int start,int end)
    {
        if(start>=end) return 0;
        int invcnt=0;
        int mid=(start+end)/2;
        invcnt+=mergesort(nums,start,mid);
        invcnt+=mergesort(nums,mid+1,end);
        invcnt+=merge(nums,start,mid,end);
        return invcnt;
        
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};



//  Brute force 
// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int pair=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 if(nums[i]>2LL*nums[j])
//                     pair++;
//             }
//         }
//         return pair;
//     }
// };