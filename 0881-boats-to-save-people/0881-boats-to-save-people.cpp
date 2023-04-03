class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int cnt=0,i=0,j=people.size()-1;
        while(i<=j)
        {
            // minimum wt+maxm wt
            if(people[i]+people[j]<=limit)
                i++,j--;
            else
                j--;  
            cnt++; 
        }
        return cnt;
    }
};