class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int i=0,n=h.size(),hsum=0;
        priority_queue<int>pq;
        while(i<n-1)
        {
            if(h[i+1]>h[i])
            {
                hsum+=(h[i+1]-h[i]);
                pq.push(h[i+1]-h[i]);
                while(hsum>bricks&&ladders>0)
                {
                    hsum-=pq.top();
                    pq.pop();
                    ladders-=1;
                }
                if(hsum>bricks&&ladders==0)
                    break;
            }
            i++;
        }
        return i;
    }
};