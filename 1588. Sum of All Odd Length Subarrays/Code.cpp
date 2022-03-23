class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            // total no of odd length sub array possible from index i
            int total=ceil(((n-i)*(i+1))/(2.0));
               sum+=arr[i]*total; 
        }
        return sum;
    }
};