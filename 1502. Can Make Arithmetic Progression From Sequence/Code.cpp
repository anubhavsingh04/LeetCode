class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        vector<bool>v;
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size()-1;i++)
        {
            if(2*arr[i]==(arr[i-1]+arr[i+1]))
                v.push_back(true);
            else
            return false;
        }
        return true;
    }
};