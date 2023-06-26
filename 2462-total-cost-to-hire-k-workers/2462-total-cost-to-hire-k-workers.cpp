class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        long long n=costs.size(),i=0,j=n-1,ans=0;

        priority_queue<long long,vector<long long>,greater<long long>>pq1,pq2;
        while(k--){
            while(pq1.size()<c && i<=j) pq1.push(costs[i++]);
            while(pq2.size()<c && j>=i) pq2.push(costs[j--]);
            int a=pq1.size()>0?pq1.top():INT_MAX;
            int b=pq2.size()>0?pq2.top():INT_MAX;
            // cout<<a<<" "<<b<<"\n";
            if(a<=b){
                ans+=a;
                pq1.pop();
            }else{
                ans+=b;
                pq2.pop();
            }
            // cnt++;
        }
        return ans;
    }
};