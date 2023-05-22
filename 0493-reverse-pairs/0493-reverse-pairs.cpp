class Solution {
public:
    int merge(vector<int>&nums,int start,int mid,int end)
    {
        int invcnt=0;
        int j=mid+1;
        for(int i=start;i<=mid;i++)
        {
            while(j<=end && nums[i]>2LL*nums[j]) {
                j++;
            }
            invcnt+=j-(mid+1); 
        }
        //j ek aage badh jayega isliye 6,8  1,2,3  (mid+1 is pointing at 1 j will be at 3 (will do 2-0))
        int left=start,right=mid+1;
        vector<int>v;
        while(left<=mid && right<=end)
        {
            if(nums[left]<=nums[right]) v.push_back(nums[left++]);
            else v.push_back(nums[right++]);
        }
        while(left<=mid ) v.push_back(nums[left++]);
        while(right<=end) v.push_back(nums[right++]);
        
        for(int i=start;i<=end;i++) {
            nums[i]=v[i-start];
        }
        return invcnt;
    }
    int mergesort(vector<int>&nums,int start,int end)
    {
        int invcnt=0;
        int mid=(start+end)/2;
        if(start>=end) return invcnt;
        invcnt+=mergesort(nums,start,mid);
        invcnt+=mergesort(nums,mid+1,end);
        invcnt+=merge(nums,start,mid,end);
        return invcnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};