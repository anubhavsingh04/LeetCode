class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // temp array to store length of longest incr subsequence
        vector<int> temp;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            
        // if the temp array is empty or the last element of
        // temp array is smaller than the current element of nums array
            if(temp.size() == 0 || temp.back() < nums[i])
                temp.push_back(nums[i]);
            else{
                
        // if the last element of temp is not smaller than the current element of nums array
        // then we will find the lowest element in temp array which is greater or equal to 
        // nums[i] and replace it with nums[i] because by doing this the length of the longest 
        // subsequence will not be affected and the value at each index in temp array will decrease             // which will help us to accomodate more elements to get the maximum incr subsequence
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }
        return temp.size();
    }
};
