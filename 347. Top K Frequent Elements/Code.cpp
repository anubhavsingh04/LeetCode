class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(auto it=m.begin();it!=m.end();it++)
        {
            pq.push({it->second,it->first});
        }
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans ;
    }
};
