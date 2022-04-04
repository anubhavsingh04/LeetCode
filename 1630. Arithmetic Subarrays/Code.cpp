class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
     
	vector<bool> res;
	for(int i=0; i<l.size(); i++)                             // O(m)
	{
		if(r[i] - l[i] < 2) res.push_back(true);
		else
		{
			vector<int> temp(nums.begin() + l[i], nums.begin() + r[i] + 1);         // O(n) , creating subarray
		    sort(temp.begin(), temp.end());                                        // O(n^2 * log(n))  , sorting
			bool flag = false;
			int diff = temp[1] - temp[0];
			for(int j=2; j <= r[i]-l[i]; j++)                                    // O(n) , check if subarray is AP
			{
				if(temp[j] - temp[j-1] != diff)
				{
					flag = true;
					break;
				}
			}
			res.push_back(!flag);
		}
	}
	return res;          
}
};