class Solution {
public:
    bool ispossible(vector<int>&piles,long long h,long long mid)
    {
        long long hour=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%mid==0)
            {
                hour+=piles[i]/mid;
            }
            else 
            {
                hour+=(1+piles[i]/mid);
            }
        }
        return hour<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long start=1,end=1e9;
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            if(ispossible(piles,h,mid))
            {
                end=mid-1;
            }
            else 
            {
                start=mid+1;
            }
        }
        return start;
    }
};