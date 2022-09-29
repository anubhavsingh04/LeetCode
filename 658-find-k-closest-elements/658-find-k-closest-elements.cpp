class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>v;
        for(int i=0;i<arr.size();i++)
        {
            v.push_back({abs(arr[i]-x),arr[i]});
        }
        priority_queue<pair<int,int>>pq;
        for(auto &i:v)
        {
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};