class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            
            if (arr[i] * (n-i) >= target) 
                return int(round((target - 0.0001) / (n - i)));
            
            target -= arr[i];
        }
        
        return arr[n-1];
    }
};