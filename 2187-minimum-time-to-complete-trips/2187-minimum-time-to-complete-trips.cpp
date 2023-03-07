class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start=0,end=1e14;
        while(start<=end)
        {
            long long trips=0;
            long long mid=start+(end-start)/2;
            for(long long i=0;i<time.size();i++)
            {
                trips+=mid/time[i];
            }
            if(trips<totalTrips){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return start;
    }
};