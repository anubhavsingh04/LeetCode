class Solution {
public:
    int minCost(string colors, vector<int>& neededtime) {
        int time=0;
        int n=colors.size();
        int sum=0;
        for(int i=1;i<n;i++)
        {
            if(colors[i]==colors[i-1])
            {
                sum+=neededtime[i-1];
                int maxi=neededtime[i-1];
                while(colors[i]==colors[i-1])
                {
                    maxi=max(maxi,neededtime[i]);
                    sum+=neededtime[i];
                    i++;
                }
                sum-=maxi;
            }
        }
        return sum;
    }
};