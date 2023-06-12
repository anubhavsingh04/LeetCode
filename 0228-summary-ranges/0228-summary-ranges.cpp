class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string>ans;
        if(n==0)  return ans;
        string s=to_string(nums[0]);
        int prev=nums[0];
        for(int i=1;i<n;i++)
        {
            if(prev+1!=nums[i])
            {
                if(to_string(prev)==s){
                    ans.push_back(s);
                    s=to_string(nums[i]); 
                }  
                else {
                    s+="->";
                    s+=to_string(prev);
                    ans.push_back(s);
                    s=to_string(nums[i]); 
                }
            }
            prev=nums[i];
        }
        if(to_string(prev)==s){
            ans.push_back(s);
            s=to_string(nums[n-1]); 
        }  
        else {
            s+="->";
            s+=to_string(prev);
            ans.push_back(s);
            s=to_string(nums[n-1]); 
        }
        return ans;
    }
};