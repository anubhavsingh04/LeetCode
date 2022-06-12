class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1)
            return stones[0];
        for(int i=0;i<n;i++)
        {
            sort(stones.begin(),stones.end());
            stones[n-1]=(stones[n-1]-stones[n-2]);
            stones[n-2]=0;
        }
        return stones[n-1];
    }
};