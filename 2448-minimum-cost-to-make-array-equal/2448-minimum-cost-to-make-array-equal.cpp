class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long sum=0,n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            sum+=v[i].second;
        }
        long long total=0,median=0;
        int i=0;
        // cout<<(sum+1)/2;
        while(total<(sum+1)/2 && i<n)
        {
            total+=1LL*v[i].second;
            median=v[i].first;
            // cout<<median<<endl;
            i++;
        }
        // cout<<median<<endl;
        long long amount=0;
        for(int i=0;i<n;i++)
        {
            amount+=abs(nums[i]-median)*cost[i];
            // cout<<amount<<endl;
        }
        return amount;
    }
};

