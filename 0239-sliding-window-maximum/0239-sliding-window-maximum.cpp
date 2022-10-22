class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int i=0,j=0,n=nums.size();
        priority_queue<pair<int,int>>pq; // element(nums[i]) ,index(j)
        while(j<n)
        {
            pq.push({nums[j],j});
            if(j-i+1<k)
            {
                j++;
            }
            else if((j-i+1)==k)
            {
                while(pq.top().second<i)
                {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
                i++,j++;
            }
        }
        return ans;
    }
};