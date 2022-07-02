// array size is even as per question 
// here i is the even pointer and j is the odd pointer 
// move i forward by 2 unit untill nums[i] is even, 
// if i reaches out at last index then break
// similarly move j backward 2 unit untill nums[j] is odd 
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        
        while(i<nums.size())
        {
            while(i<nums.size() && (nums[i]&1)==0)
            i+=2;
            
            if(i==nums.size()) break;
            
            while(j>=0 && (nums[j]&1)==1)
                j-=2;
            
            swap(nums[i],nums[j]);
        }
        return nums;
    }
};