class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        int n=a.size();
        if(n<m*k)return -1;
        
        int left=*min_element(a.begin(),a.end());
        int right=*max_element(a.begin(),a.end());
        
        while(left<right)
        {
            int c=0,bouquet=0;

            int mid=(left+right)/2;
            for(int i=0;i<n;i++)
            {
                if(a[i]<=mid)c++;
                else c=0;
                
                if(c==k)
                {
                    bouquet++;
                    c=0;
                }
            }
            
            if(bouquet<m)left=mid+1;
            else right=mid;
        }
        
        return left;
    }
};