class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i=0,n=arr.size();
        int j=n-1;
        if(n<3) return false;
        while(i<n-2 && arr[i+1]>arr[i]) i++;
        while(j>1 && arr[j-1]>arr[j]) j--;
        return i==j;
        
    }
};