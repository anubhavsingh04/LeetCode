class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        long long n=costs.size(),start=0,end=n-1,ans=0;
        priority_queue<long long,vector<long long>,greater<long long>>pq,pq1;
        while(k--)
        {
            while(pq.size()<c && start<=end) pq.push(costs[start++]);
            while(pq1.size()<c && end>=start) pq1.push(costs[end--]);
            int a=1e9,b=1e9;
            if(pq.size()>0) a=pq.top();
            if(pq1.size()>0) b=pq1.top();
            if(a<=b) {
                ans+=a;
                pq.pop();
            }
            else {
                ans+=b;
                pq1.pop();
            }
        }
        return ans;
    }
};
