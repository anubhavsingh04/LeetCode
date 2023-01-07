class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),totalcost=0,totalfuel=0;
        int curr_fuel=0,start=0;
        for(int i=0;i<n;i++)
        {
            totalcost+=cost[i];
            totalfuel+=gas[i];
            curr_fuel+=gas[i]-cost[i];
            if(curr_fuel<0)
            {
                start=i+1;
                curr_fuel=0;
            }
        }
        if(totalcost>totalfuel) return -1;
        return start;
    }
};