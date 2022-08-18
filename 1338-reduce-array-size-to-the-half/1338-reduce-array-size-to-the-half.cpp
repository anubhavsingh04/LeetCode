// Size of set will be min when we remove element having highest freq 
// put the freq of each element in priority_queue
// remove elements from array having highest freq unitil total no of removed elements<size/2

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size=arr.size();
        unordered_map<int,int>m;
        for(auto &i:arr)
        {
            m[i]++;
        }
        priority_queue<int>pq;
        for(auto &i:m)
        {
            pq.push(i.second);
        }
        int removed=0;
        int ans=0;
        while(removed<size/2)
        {
            removed+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};