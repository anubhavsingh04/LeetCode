class Solution {
public:
    static bool cmp(int a,int b)
    {
        return a>b;
    }
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>even,odd;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i&1) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int>()); // we can also use cmp fn implemennted above 
        for(int i=0;i<n;i++)
        {
            if(i&1)
            {
                nums[i]=odd[0];
                odd.erase(odd.begin());
            }
            else{
                nums[i]=even[0];
                even.erase(even.begin());
            }
        }
        return nums;
    }
};