class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0,n=h.size();
        // pehle jitne ladder hai lets suppose unka use kr lete hai jumping ke liye 
        while(i<n-1&&pq.size()<ladders)
        {
            int jumpheight=h[i+1]-h[i];
            if(jumpheight>0)
                pq.push(jumpheight);
            i++;
        }
        // ab bricks ka check krenge ki kya ham pehle brick use kr skte the 
        // means agr hamne choti height ke liye ladder use kr diya hai
        // i.e. priority queu me jo min element aur abhi hame jo height jump krni hai vo is min               //element se jada hai matlab hame vaha pe bricks use krni chahiye thi 
        // to min element ke jgh brick use krenge aur priority q me jump height push kr denge 
        while(i<n-1)
        {
            int jumpheight=h[i+1]-h[i];
           if(jumpheight>0)
           {
                if(!pq.empty()&&jumpheight>pq.top())
                {
                    bricks-=pq.top();
                    pq.pop();
                    pq.push(jumpheight);
                }
                else 
                {
                    bricks-=jumpheight;
                }
           }
            if(bricks<0)
                return i;
            i++;
        }
        return i;
    }
};



// class Solution {
// public:
//     int furthestBuilding(vector<int>& h, int bricks, int ladders) {
//         int i=0,n=h.size(),hsum=0;
//         priority_queue<int>pq;
//         while(i<n-1)
//         {
//             if(h[i+1]>h[i])
//             {
//                 hsum+=(h[i+1]-h[i]);
//                 pq.push(h[i+1]-h[i]);
//                 while(hsum>bricks&&ladders>0)
//                 {
//                     hsum-=pq.top();
//                     pq.pop();
//                     ladders-=1;
//                 }
//                 if(hsum>bricks&&ladders==0)
//                     break;
//             }
//             i++;
//         }
//         return i;
//     }
// };