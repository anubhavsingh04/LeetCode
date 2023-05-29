class Solution {
public:
    int b_search(vector<int>&v,int x)
    {
        int low=0,high=v.size()-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(v[mid]<x) low=mid+1;
            else high=mid-1;
        }
        cout<<low<<' ';
        return low;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0],high=matrix[n-1][n-1];
        while(low<=high)
        {
            int mid=(low+high)>>1;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                cnt+=b_search(matrix[i],mid);
            }
            if(cnt<k) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};