// water above any building will be level of water above that building -height of building 
// to find the level of water above any buiding find the maxm on the left
// and find the maximum on the right 
// take the minimum of from maxm_left and maxm_right  

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>maxm_left(n),maxm_right(n);
        
        maxm_left[0]=height[0];
        for(int i=1;i<n;i++)
        {
            maxm_left[i]=max(maxm_left[i-1],height[i]);
        }
        
        maxm_right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxm_right[i]=max(maxm_right[i+1],height[i]);
        }
        
        int water=0;
        for(int i=0;i<n;i++)
        {
            water+=(min(maxm_left[i],maxm_right[i])-height[i]);
        }
        return water;
    }
};